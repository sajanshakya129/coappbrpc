function(find_python_module module)
  string(TOUPPER ${module} module_upper)
  if(NOT PY_${module_upper})
    if(ARGC GREATER 1 AND ARGV1 STREQUAL "REQUIRED")
      set(${module}_FIND_REQUIRED TRUE)
    endif()
    # A module's location is usually a directory, but for binary modules
    # it's a .so file.
    execute_process(COMMAND "${PYTHON_EXEC}" "-c" 
      "import re, ${module}; print re.compile('/__init__.py.*').sub('',${module}.__file__)"
      RESULT_VARIABLE _${module}_status 
      OUTPUT_VARIABLE _${module}_location
      ERROR_VARIABLE  _${module}_error
      ERROR_QUIET OUTPUT_STRIP_TRAILING_WHITESPACE)
    if(NOT _${module}_status)
      set(PY_${module_upper} ${_${module}_location} CACHE STRING 
        "Location of Python module ${module}")
    endif(NOT _${module}_status)
  endif(NOT PY_${module_upper})
  find_package_handle_standard_args(PY_${module} DEFAULT_MSG PY_${module_upper})
endfunction(find_python_module)


#include(FindPythonModuleExt)
#find_python_module(python-pip)
#message(${_python-pip_status})
#message("----------------------------------")
#execute_process(
#COMMAND  ${PYTHON_EXECUTABLE} "-m pip"
#WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
#RESULT_VARIABLE pip_exists
#)
#if(NOT (${pip_exists} EQUAL 0))
#message("PIP is not found in your system. Downloading Pip and installing it now.")
#include(DowloadInstallPipModuleExt)
#else(${pip_exists} EQUAL 0)
#message("PIP is found already installed in your system")
#endif(NOT (${pip_exists} EQUAL 0))
