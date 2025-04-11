## Machine Learning for Intel(R) Xeon(R) E5-2620

### 1. Installation of Intel OpenAPI C++ Compiler (Debian)
```bash
sudo apt install -y gpg-agent wget cmake pkg-config build-essential git

wget -O- https://apt.repos.intel.com/intel-gpg-keys/GPG-PUB-KEY-INTEL-SW-PRODUCTS.PUB | gpg --dearmor | sudo tee /usr/share/keyrings/oneapi-archive-keyring.gpg > /dev/null

echo "deb [signed-by=/usr/share/keyrings/oneapi-archive-keyring.gpg] https://apt.repos.intel.com/oneapi all main" | sudo tee /etc/apt/sources.list.d/oneAPI.list

sudo apt update && sudo apt install intel-oneapi-hpc-toolkit
```
#### *(Optional)* Install Radare2 for ASM debugging
```bash
git clone https://github.com/radareorg/radare2 ~/radare2
cd ~/radare2; sys/install.sh
```

### 2. Setup variables
```bash
source /opt/intel/oneapi/setvars.sh
```

### 3. Build the project
```bash
cmake -B build/ .
cmake --build build/ --config Debug # or Release
./build/ml
```

#### *Alternatively*
```bash
. full-auto.sh [Release / Debug] # For clean build
. semi-auto.sh [Release / Debug] # For build
```
