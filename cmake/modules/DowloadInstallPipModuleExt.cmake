#Downloading and Installing PIP module for python
set(PIP_INSTALL_FILENAME get-pip.py)
set(PIP_ADDR https://bootstrap.pypa.io/get-pip.py)

include(FindWget)
if(WGET_FOUND)
    execute_process(
                  COMMAND ${WGET_EXECUTABLE} ${PIP_ADDR}
                  WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
                  RESULT_VARIABLE pip_download_result
                  OUTPUT_VARIABLE pip_download_output
                 )
endif(WGET_FOUND)

if(${pip_download_result} EQUAL 0)
  execute_process(
                  COMMAND ${PYTHON_EXECUTABLE} ${PROJECT_BINARY_DIR}/${PIP_INSTALL_FILENAME} --user
                  WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
                  RESULT_VARIABLE pip_inst_result
                  OUTPUT_VARIABLE pip_inst_output
                 )
endif(${pip_download_result} EQUAL 0)

if(${pip_inst_result} EQUAL 0)
  message("Python module PIP is installed in your system.")
else(NOT(${pip_inst_result} EQUAL 0))
  message("ERROR:Please install pip module for python manually.")
endif(${pip_inst_result} EQUAL 0)
