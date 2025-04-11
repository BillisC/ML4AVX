# -- SEMI AUTOMATIC BUILD --
# Syntax: . semi-auto.sh [Debug/Release]

RED="\e[31m"
GREEN="\e[32m"
CLEAR="\e[0m"

BUILD_TYPE=None

# Check parameter
if [ -z "$1" ]
then
  echo -e "${RED}Missing build type parameter..defaulting to Debug${CLEAR}";
  BUILD_TYPE=Debug
else
  echo -e "${GREEN}Using build type $1${CLEAR}";
  BUILD_TYPE=$1
fi

# Build project
cmake --build build/ --config BUILD_TYPE
# Execute
./build/ml4avx
