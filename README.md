# Protobuf RPC over CoAP

## Dependency
Install [libpbrpc](https://github.com/sajanshakya129/libpbrpc.git) library in your system.


##installation
```
git clone --recurse-submodules https://github.com/sajanshakya129/coappbrpc
mkdir build && cd build
cmake ..
make
sudo make install
```

## Running Server
```
./build/src/pbrpc_srv
```
## Compiling and Running Client(work on progress)
```
./src/compile.sh
./client
```