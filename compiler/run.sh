#!/bin/bash
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

ROOT_DIR=$SCRIPT_DIR/..

MODEL=$1
TARGET=$2
OUTPUT=$3

MODEL_NAME=`basename $MODEL`
BUILDEND=_${MODEL_NAME:: -4}

FPGA_CPU_DIR=$ROOT_DIR/compiler/fpga$BUILDEND/CPUCode


NEB_COMPILER_DIR=$ROOT_DIR/compiler/java
SKELETON_DIR=$ROOT_DIR/compiler/skeletons

CPP_DIR=$SKELETON_DIR/cpp
OPENCL_DIR=$SKELETON_DIR/openCL
FPGA_DIR=$SKELETON_DIR/fpga
MP_DIR=$SKELETON_DIR/cpp_mp

CPP_SRCS="$CPP_DIR/MonteCarlo.cpp $CPP_DIR/utils.cpp $CPP_DIR/utils.h $CPP_DIR/Makefile"
OPENCL_SRCS="$OPENCL_DIR/MonteCarlo.cpp $OPENCL_DIR/utils.cpp $OPENCL_DIR/utils.h $OPENCL_DIR/Makefile $OPENCL_DIR/CL"
MP_SRCS="$MP_DIR/MonteCarlo.cpp $MP_DIR/utils.cpp $MP_DIR/utils.h $MP_DIR/Makefile"

ORACLE=/usr/lib/jvm/jdk-8-oracle-x64
JAVA=$ORACLE/bin/java
JAVAC=$ORACLE/bin/javac

if [ ! -d "$ORACLE" ]; then
  JAVA="java"
  JAVAC="javac"
fi

NEB_COMPILER_CLASSPATH="$NEB_COMPILER_DIR/src:$NEB_COMPILER_DIR/lib/*:$NEB_COMPILER_DIR/gen"
NEB="$JAVA -cp $NEB_COMPILER_CLASSPATH com.neb.Main" 

HEADER=MonteCarlo.h


BUILDS=($TARGET)

if [[ $* == *-h* ]]; then
  echo "-- USAGE -- "
  echo "ARGS"
  echo "modelFile targetArchitecture"    
 
  echo ""

  echo "FLAGS"
  echo "-b    Rebuild neb compiler. Use if you've made changes to the Java source."
  echo "-f    Mock random number generation for fast but incorrect execution."
  echo "-k    Don't clean existing builds."

  echo ""
  echo "e.g. run.sh randomWalk.neb cpp -c"
  exit
fi

if [[ $* == *-b* ]]; then
  echo "Building Neb compiler..."
  make -C $NEB_COMPILER_DIR/src JAVAC=$JAVAC
fi

if [[ $* == *-f* ]]; then
  echo "Using fast random numbers..."
  FLAGS="-f"
else
  FLAGS=""
fi

if [[ $* == *-n* ]]; then
  echo "Disabling optimisations..."
  FLAGS="$FLAGS -n" 
fi

for i in "${BUILDS[@]}"
do
  BUILD=$OUTPUT/"$i"$BUILDEND
  if [[ $* != *-k* ]]; then
    echo "Cleaning $BUILD ..."
    rm -rf $BUILD
  fi

  mkdir $BUILD

  KERNEL=$BUILD/Template.cl
  HEADER=$BUILD/MonteCarlo.h
  MAXC=$BUILD/CPUCode/NebStreamCpuCode.cpp
  MAXK=$BUILD/EngineCode/src/nebstream/NebStreamKernel.maxj
  MAXM=$BUILD/EngineCode/src/nebstream/NebStreamManager.maxj

  echo $BUILD

  case $i in 
    "cpp" )
      cp $CPP_SRCS $BUILD
      TARGET=cpp
      ;;
    "openCL" )
      cp $OPENCL_SRCS $BUILD -r
      TARGET=openCL
      ;;
    "fpga" )
      cp -r $FPGA_DIR/* $BUILD
      TARGET=maxeler
      ;;
    "mp" )
      cp $MP_SRCS $BUILD 
      TARGET=cpp #Todo
      ;;
  esac

  $NEB -m $MODEL -h $HEADER -k $KERNEL --maxelerC $MAXC --maxelerKernel $MAXK --maxelerManager $MAXM -t $TARGET $FLAGS
  echo $NEB -m $MODEL -h $HEADER -k $KERNEL --maxelerC $MAXC --maxelerKernel $MAXK --maxelerManager $MAXM -t $TARGET $FLAGS  

  if [ $i == "fpgaRun"  ]; then
    ssh maxnode2 "make -C $FPGA_CPU_DIR RUNRULE=Simulation build"
  else
    if [[ $* == *-m* ]]; then
      make -C $BUILD
    fi
  fi
done

echo ""
echo "---                      ---"
echo "------ Build Complete ------"
echo "---                      ---"
echo ""

if [[ $* == *-r* ]]; then
	for i in "${BUILDS[@]}"
	do
	  echo "Running $i..."
	  if [ $i == "fpgaRun" ]; then
	    ssh maxnode2 "make -C $FPGA_CPU_DIR RUNRULE=Simulation run"
	  else
	    (cd $BUILD; make; ./a.out)
	  fi
	done
fi
