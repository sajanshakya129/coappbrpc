# Protobuf RPC over CoAP

## Dependency
Please install following application to build and run coappbrpc
```
sudo apt-get install cmake build-essential dh-autoreconf python python-pip
```

### Installation of LibCoAP
```
git clone https://github.com/obgm/libcoap.git
cd libcoap

```
OPTIONAL:You might need to install pkg-config in your system if 'pkg-config' is not found.
```
sudo apt-get install pkg-config
```
Then configure libcoap and install libcoap
```
./autogen.sh
./configure --disable-doxygen --disable-manpages
make
sudo make install
sudo ldconfig /usr/local/lib
```

## Installation
```
git clone --recurse-submodules https://github.com/sajanshakya129/coappbrpc
mkdir build && cd build
cmake ..
make
sudo make install
```

## Running Server
```
cd build/src/
./pbrpc_srv
```
## Compiling and Running Client(work on progress)
```
compile_client.sh
./client
```
