#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Algorithms/DynamicProgramming/01KnapsackProblem.o \
	${OBJECTDIR}/Algorithms/DynamicProgramming/FloydWarshallAlgorithm.o \
	${OBJECTDIR}/Algorithms/DynamicProgramming/LongestCommonSubsequence.o \
	${OBJECTDIR}/Algorithms/DynamicProgramming/MatrixChainMultiplication.o \
	${OBJECTDIR}/Algorithms/DynamicProgramming/MultiStageGraph.o \
	${OBJECTDIR}/Algorithms/DynamicProgramming/SubsetSumProblem.o \
	${OBJECTDIR}/Algorithms/GreedyAlgorithms/DijkstraAlgorithm.o \
	${OBJECTDIR}/Algorithms/GreedyAlgorithms/GreedyKnapsackProblem.o \
	${OBJECTDIR}/Algorithms/GreedyAlgorithms/HuffmanCodes.o \
	${OBJECTDIR}/Algorithms/GreedyAlgorithms/JobSequencingWithDeadlines.o \
	${OBJECTDIR}/Algorithms/GreedyAlgorithms/PrimsAlgorithmWithHeap.o \
	${OBJECTDIR}/Algorithms/SortingTechniques/BubbleSort.o \
	${OBJECTDIR}/Algorithms/SortingTechniques/BucketSort.o \
	${OBJECTDIR}/Algorithms/SortingTechniques/CountingSort.o \
	${OBJECTDIR}/Algorithms/SortingTechniques/InsertionSort.o \
	${OBJECTDIR}/Algorithms/SortingTechniques/MergeSort.o \
	${OBJECTDIR}/Algorithms/SortingTechniques/QuickSort.o \
	${OBJECTDIR}/Algorithms/SortingTechniques/RadixSort.o \
	${OBJECTDIR}/Algorithms/SortingTechniques/SelectionSort.o \
	${OBJECTDIR}/Algorithms/SortingTechniques/ShellSort.o \
	${OBJECTDIR}/CPracticeQuestions/Armstrong.o \
	${OBJECTDIR}/CPracticeQuestions/ArrayOfPointerMultidimensional.o \
	${OBJECTDIR}/CPracticeQuestions/BasicStringsCharacters.o \
	${OBJECTDIR}/CPracticeQuestions/BasicStringsOperations.o \
	${OBJECTDIR}/CPracticeQuestions/ConvertIntToChar.o \
	${OBJECTDIR}/CPracticeQuestions/DeleteOccuranceOfC.o \
	${OBJECTDIR}/CPracticeQuestions/FahrenheitCelcius.o \
	${OBJECTDIR}/CPracticeQuestions/Fibonacci.o \
	${OBJECTDIR}/CPracticeQuestions/HalfPyramidStar.o \
	${OBJECTDIR}/CPracticeQuestions/ImplementingStrCat.o \
	${OBJECTDIR}/CPracticeQuestions/ImplementingStrCmp.o \
	${OBJECTDIR}/CPracticeQuestions/ImplementingStrCpy.o \
	${OBJECTDIR}/CPracticeQuestions/PalindromeNumber.o \
	${OBJECTDIR}/CPracticeQuestions/PointerArrayCopy.o \
	${OBJECTDIR}/CPracticeQuestions/PointerArrays.o \
	${OBJECTDIR}/CPracticeQuestions/PointerSwapping1.o \
	${OBJECTDIR}/CPracticeQuestions/Prime.o \
	${OBJECTDIR}/CPracticeQuestions/PyramidStarPattern.o \
	${OBJECTDIR}/DataStructures/GraphsPrograms/BfsDfs.o \
	${OBJECTDIR}/DataStructures/GraphsPrograms/CheckingForAcyclicGraph.o \
	${OBJECTDIR}/DataStructures/GraphsPrograms/TopologicalSort.o \
	${OBJECTDIR}/DataStructures/HashingPrograms/ChainingInHashing.o \
	${OBJECTDIR}/DataStructures/HashingPrograms/OpenAddressingDoubleHashing.o \
	${OBJECTDIR}/DataStructures/HeapsPrograms/BuiltMaxHeap.o \
	${OBJECTDIR}/DataStructures/HeapsPrograms/HeapSort.o \
	${OBJECTDIR}/DataStructures/HeapsPrograms/OperationsOnHeap.o \
	${OBJECTDIR}/DataStructures/LinkedListPrograms/ComprehensiveLinkedList.o \
	${OBJECTDIR}/DataStructures/LinkedListPrograms/DoublyLinkedList.o \
	${OBJECTDIR}/DataStructures/RecursionPrograms/TowerOfHanoi.o \
	${OBJECTDIR}/DataStructures/StackQueuesPrograms/InfixToPostfixUsingStack.o \
	${OBJECTDIR}/DataStructures/StackQueuesPrograms/QueueUsingCircularArray.o \
	${OBJECTDIR}/DataStructures/StackQueuesPrograms/QueueUsingLinkedList.o \
	${OBJECTDIR}/DataStructures/StackQueuesPrograms/StackUsingArrays.o \
	${OBJECTDIR}/DataStructures/StackQueuesPrograms/StackUsingLinkedList.o \
	${OBJECTDIR}/DataStructures/TreesPrograms/ComprehensiveTreeProgram.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/datastructures-algorithms-inc

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/datastructures-algorithms-inc: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/datastructures-algorithms-inc ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Algorithms/DynamicProgramming/01KnapsackProblem.o: Algorithms/DynamicProgramming/01KnapsackProblem.c
	${MKDIR} -p ${OBJECTDIR}/Algorithms/DynamicProgramming
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Algorithms/DynamicProgramming/01KnapsackProblem.o Algorithms/DynamicProgramming/01KnapsackProblem.c

${OBJECTDIR}/Algorithms/DynamicProgramming/FloydWarshallAlgorithm.o: Algorithms/DynamicProgramming/FloydWarshallAlgorithm.c
	${MKDIR} -p ${OBJECTDIR}/Algorithms/DynamicProgramming
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Algorithms/DynamicProgramming/FloydWarshallAlgorithm.o Algorithms/DynamicProgramming/FloydWarshallAlgorithm.c

${OBJECTDIR}/Algorithms/DynamicProgramming/LongestCommonSubsequence.o: Algorithms/DynamicProgramming/LongestCommonSubsequence.c
	${MKDIR} -p ${OBJECTDIR}/Algorithms/DynamicProgramming
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Algorithms/DynamicProgramming/LongestCommonSubsequence.o Algorithms/DynamicProgramming/LongestCommonSubsequence.c

${OBJECTDIR}/Algorithms/DynamicProgramming/MatrixChainMultiplication.o: Algorithms/DynamicProgramming/MatrixChainMultiplication.c
	${MKDIR} -p ${OBJECTDIR}/Algorithms/DynamicProgramming
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Algorithms/DynamicProgramming/MatrixChainMultiplication.o Algorithms/DynamicProgramming/MatrixChainMultiplication.c

${OBJECTDIR}/Algorithms/DynamicProgramming/MultiStageGraph.o: Algorithms/DynamicProgramming/MultiStageGraph.c
	${MKDIR} -p ${OBJECTDIR}/Algorithms/DynamicProgramming
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Algorithms/DynamicProgramming/MultiStageGraph.o Algorithms/DynamicProgramming/MultiStageGraph.c

${OBJECTDIR}/Algorithms/DynamicProgramming/SubsetSumProblem.o: Algorithms/DynamicProgramming/SubsetSumProblem.c
	${MKDIR} -p ${OBJECTDIR}/Algorithms/DynamicProgramming
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Algorithms/DynamicProgramming/SubsetSumProblem.o Algorithms/DynamicProgramming/SubsetSumProblem.c

${OBJECTDIR}/Algorithms/GreedyAlgorithms/DijkstraAlgorithm.o: Algorithms/GreedyAlgorithms/DijkstraAlgorithm.c
	${MKDIR} -p ${OBJECTDIR}/Algorithms/GreedyAlgorithms
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Algorithms/GreedyAlgorithms/DijkstraAlgorithm.o Algorithms/GreedyAlgorithms/DijkstraAlgorithm.c

${OBJECTDIR}/Algorithms/GreedyAlgorithms/GreedyKnapsackProblem.o: Algorithms/GreedyAlgorithms/GreedyKnapsackProblem.c
	${MKDIR} -p ${OBJECTDIR}/Algorithms/GreedyAlgorithms
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Algorithms/GreedyAlgorithms/GreedyKnapsackProblem.o Algorithms/GreedyAlgorithms/GreedyKnapsackProblem.c

${OBJECTDIR}/Algorithms/GreedyAlgorithms/HuffmanCodes.o: Algorithms/GreedyAlgorithms/HuffmanCodes.c
	${MKDIR} -p ${OBJECTDIR}/Algorithms/GreedyAlgorithms
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Algorithms/GreedyAlgorithms/HuffmanCodes.o Algorithms/GreedyAlgorithms/HuffmanCodes.c

${OBJECTDIR}/Algorithms/GreedyAlgorithms/JobSequencingWithDeadlines.o: Algorithms/GreedyAlgorithms/JobSequencingWithDeadlines.c
	${MKDIR} -p ${OBJECTDIR}/Algorithms/GreedyAlgorithms
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Algorithms/GreedyAlgorithms/JobSequencingWithDeadlines.o Algorithms/GreedyAlgorithms/JobSequencingWithDeadlines.c

${OBJECTDIR}/Algorithms/GreedyAlgorithms/PrimsAlgorithmWithHeap.o: Algorithms/GreedyAlgorithms/PrimsAlgorithmWithHeap.c
	${MKDIR} -p ${OBJECTDIR}/Algorithms/GreedyAlgorithms
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Algorithms/GreedyAlgorithms/PrimsAlgorithmWithHeap.o Algorithms/GreedyAlgorithms/PrimsAlgorithmWithHeap.c

${OBJECTDIR}/Algorithms/SortingTechniques/BubbleSort.o: Algorithms/SortingTechniques/BubbleSort.c
	${MKDIR} -p ${OBJECTDIR}/Algorithms/SortingTechniques
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Algorithms/SortingTechniques/BubbleSort.o Algorithms/SortingTechniques/BubbleSort.c

${OBJECTDIR}/Algorithms/SortingTechniques/BucketSort.o: Algorithms/SortingTechniques/BucketSort.c
	${MKDIR} -p ${OBJECTDIR}/Algorithms/SortingTechniques
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Algorithms/SortingTechniques/BucketSort.o Algorithms/SortingTechniques/BucketSort.c

${OBJECTDIR}/Algorithms/SortingTechniques/CountingSort.o: Algorithms/SortingTechniques/CountingSort.c
	${MKDIR} -p ${OBJECTDIR}/Algorithms/SortingTechniques
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Algorithms/SortingTechniques/CountingSort.o Algorithms/SortingTechniques/CountingSort.c

${OBJECTDIR}/Algorithms/SortingTechniques/InsertionSort.o: Algorithms/SortingTechniques/InsertionSort.c
	${MKDIR} -p ${OBJECTDIR}/Algorithms/SortingTechniques
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Algorithms/SortingTechniques/InsertionSort.o Algorithms/SortingTechniques/InsertionSort.c

${OBJECTDIR}/Algorithms/SortingTechniques/MergeSort.o: Algorithms/SortingTechniques/MergeSort.c
	${MKDIR} -p ${OBJECTDIR}/Algorithms/SortingTechniques
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Algorithms/SortingTechniques/MergeSort.o Algorithms/SortingTechniques/MergeSort.c

${OBJECTDIR}/Algorithms/SortingTechniques/QuickSort.o: Algorithms/SortingTechniques/QuickSort.c
	${MKDIR} -p ${OBJECTDIR}/Algorithms/SortingTechniques
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Algorithms/SortingTechniques/QuickSort.o Algorithms/SortingTechniques/QuickSort.c

${OBJECTDIR}/Algorithms/SortingTechniques/RadixSort.o: Algorithms/SortingTechniques/RadixSort.c
	${MKDIR} -p ${OBJECTDIR}/Algorithms/SortingTechniques
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Algorithms/SortingTechniques/RadixSort.o Algorithms/SortingTechniques/RadixSort.c

${OBJECTDIR}/Algorithms/SortingTechniques/SelectionSort.o: Algorithms/SortingTechniques/SelectionSort.c
	${MKDIR} -p ${OBJECTDIR}/Algorithms/SortingTechniques
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Algorithms/SortingTechniques/SelectionSort.o Algorithms/SortingTechniques/SelectionSort.c

${OBJECTDIR}/Algorithms/SortingTechniques/ShellSort.o: Algorithms/SortingTechniques/ShellSort.c
	${MKDIR} -p ${OBJECTDIR}/Algorithms/SortingTechniques
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Algorithms/SortingTechniques/ShellSort.o Algorithms/SortingTechniques/ShellSort.c

${OBJECTDIR}/CPracticeQuestions/Armstrong.o: CPracticeQuestions/Armstrong.c
	${MKDIR} -p ${OBJECTDIR}/CPracticeQuestions
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CPracticeQuestions/Armstrong.o CPracticeQuestions/Armstrong.c

${OBJECTDIR}/CPracticeQuestions/ArrayOfPointerMultidimensional.o: CPracticeQuestions/ArrayOfPointerMultidimensional.c
	${MKDIR} -p ${OBJECTDIR}/CPracticeQuestions
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CPracticeQuestions/ArrayOfPointerMultidimensional.o CPracticeQuestions/ArrayOfPointerMultidimensional.c

${OBJECTDIR}/CPracticeQuestions/BasicStringsCharacters.o: CPracticeQuestions/BasicStringsCharacters.c
	${MKDIR} -p ${OBJECTDIR}/CPracticeQuestions
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CPracticeQuestions/BasicStringsCharacters.o CPracticeQuestions/BasicStringsCharacters.c

${OBJECTDIR}/CPracticeQuestions/BasicStringsOperations.o: CPracticeQuestions/BasicStringsOperations.c
	${MKDIR} -p ${OBJECTDIR}/CPracticeQuestions
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CPracticeQuestions/BasicStringsOperations.o CPracticeQuestions/BasicStringsOperations.c

${OBJECTDIR}/CPracticeQuestions/ConvertIntToChar.o: CPracticeQuestions/ConvertIntToChar.c
	${MKDIR} -p ${OBJECTDIR}/CPracticeQuestions
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CPracticeQuestions/ConvertIntToChar.o CPracticeQuestions/ConvertIntToChar.c

${OBJECTDIR}/CPracticeQuestions/DeleteOccuranceOfC.o: CPracticeQuestions/DeleteOccuranceOfC.c
	${MKDIR} -p ${OBJECTDIR}/CPracticeQuestions
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CPracticeQuestions/DeleteOccuranceOfC.o CPracticeQuestions/DeleteOccuranceOfC.c

${OBJECTDIR}/CPracticeQuestions/FahrenheitCelcius.o: CPracticeQuestions/FahrenheitCelcius.c
	${MKDIR} -p ${OBJECTDIR}/CPracticeQuestions
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CPracticeQuestions/FahrenheitCelcius.o CPracticeQuestions/FahrenheitCelcius.c

${OBJECTDIR}/CPracticeQuestions/Fibonacci.o: CPracticeQuestions/Fibonacci.c
	${MKDIR} -p ${OBJECTDIR}/CPracticeQuestions
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CPracticeQuestions/Fibonacci.o CPracticeQuestions/Fibonacci.c

${OBJECTDIR}/CPracticeQuestions/HalfPyramidStar.o: CPracticeQuestions/HalfPyramidStar.c
	${MKDIR} -p ${OBJECTDIR}/CPracticeQuestions
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CPracticeQuestions/HalfPyramidStar.o CPracticeQuestions/HalfPyramidStar.c

${OBJECTDIR}/CPracticeQuestions/ImplementingStrCat.o: CPracticeQuestions/ImplementingStrCat.c
	${MKDIR} -p ${OBJECTDIR}/CPracticeQuestions
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CPracticeQuestions/ImplementingStrCat.o CPracticeQuestions/ImplementingStrCat.c

${OBJECTDIR}/CPracticeQuestions/ImplementingStrCmp.o: CPracticeQuestions/ImplementingStrCmp.c
	${MKDIR} -p ${OBJECTDIR}/CPracticeQuestions
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CPracticeQuestions/ImplementingStrCmp.o CPracticeQuestions/ImplementingStrCmp.c

${OBJECTDIR}/CPracticeQuestions/ImplementingStrCpy.o: CPracticeQuestions/ImplementingStrCpy.c
	${MKDIR} -p ${OBJECTDIR}/CPracticeQuestions
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CPracticeQuestions/ImplementingStrCpy.o CPracticeQuestions/ImplementingStrCpy.c

${OBJECTDIR}/CPracticeQuestions/PalindromeNumber.o: CPracticeQuestions/PalindromeNumber.c
	${MKDIR} -p ${OBJECTDIR}/CPracticeQuestions
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CPracticeQuestions/PalindromeNumber.o CPracticeQuestions/PalindromeNumber.c

${OBJECTDIR}/CPracticeQuestions/PointerArrayCopy.o: CPracticeQuestions/PointerArrayCopy.c
	${MKDIR} -p ${OBJECTDIR}/CPracticeQuestions
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CPracticeQuestions/PointerArrayCopy.o CPracticeQuestions/PointerArrayCopy.c

${OBJECTDIR}/CPracticeQuestions/PointerArrays.o: CPracticeQuestions/PointerArrays.c
	${MKDIR} -p ${OBJECTDIR}/CPracticeQuestions
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CPracticeQuestions/PointerArrays.o CPracticeQuestions/PointerArrays.c

${OBJECTDIR}/CPracticeQuestions/PointerSwapping1.o: CPracticeQuestions/PointerSwapping1.c
	${MKDIR} -p ${OBJECTDIR}/CPracticeQuestions
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CPracticeQuestions/PointerSwapping1.o CPracticeQuestions/PointerSwapping1.c

${OBJECTDIR}/CPracticeQuestions/Prime.o: CPracticeQuestions/Prime.c
	${MKDIR} -p ${OBJECTDIR}/CPracticeQuestions
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CPracticeQuestions/Prime.o CPracticeQuestions/Prime.c

${OBJECTDIR}/CPracticeQuestions/PyramidStarPattern.o: CPracticeQuestions/PyramidStarPattern.c
	${MKDIR} -p ${OBJECTDIR}/CPracticeQuestions
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CPracticeQuestions/PyramidStarPattern.o CPracticeQuestions/PyramidStarPattern.c

${OBJECTDIR}/DataStructures/GraphsPrograms/BfsDfs.o: DataStructures/GraphsPrograms/BfsDfs.c
	${MKDIR} -p ${OBJECTDIR}/DataStructures/GraphsPrograms
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DataStructures/GraphsPrograms/BfsDfs.o DataStructures/GraphsPrograms/BfsDfs.c

${OBJECTDIR}/DataStructures/GraphsPrograms/CheckingForAcyclicGraph.o: DataStructures/GraphsPrograms/CheckingForAcyclicGraph.c
	${MKDIR} -p ${OBJECTDIR}/DataStructures/GraphsPrograms
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DataStructures/GraphsPrograms/CheckingForAcyclicGraph.o DataStructures/GraphsPrograms/CheckingForAcyclicGraph.c

${OBJECTDIR}/DataStructures/GraphsPrograms/TopologicalSort.o: DataStructures/GraphsPrograms/TopologicalSort.c
	${MKDIR} -p ${OBJECTDIR}/DataStructures/GraphsPrograms
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DataStructures/GraphsPrograms/TopologicalSort.o DataStructures/GraphsPrograms/TopologicalSort.c

${OBJECTDIR}/DataStructures/HashingPrograms/ChainingInHashing.o: DataStructures/HashingPrograms/ChainingInHashing.c
	${MKDIR} -p ${OBJECTDIR}/DataStructures/HashingPrograms
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DataStructures/HashingPrograms/ChainingInHashing.o DataStructures/HashingPrograms/ChainingInHashing.c

${OBJECTDIR}/DataStructures/HashingPrograms/OpenAddressingDoubleHashing.o: DataStructures/HashingPrograms/OpenAddressingDoubleHashing.c
	${MKDIR} -p ${OBJECTDIR}/DataStructures/HashingPrograms
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DataStructures/HashingPrograms/OpenAddressingDoubleHashing.o DataStructures/HashingPrograms/OpenAddressingDoubleHashing.c

${OBJECTDIR}/DataStructures/HeapsPrograms/BuiltMaxHeap.o: DataStructures/HeapsPrograms/BuiltMaxHeap.c
	${MKDIR} -p ${OBJECTDIR}/DataStructures/HeapsPrograms
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DataStructures/HeapsPrograms/BuiltMaxHeap.o DataStructures/HeapsPrograms/BuiltMaxHeap.c

${OBJECTDIR}/DataStructures/HeapsPrograms/HeapSort.o: DataStructures/HeapsPrograms/HeapSort.c
	${MKDIR} -p ${OBJECTDIR}/DataStructures/HeapsPrograms
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DataStructures/HeapsPrograms/HeapSort.o DataStructures/HeapsPrograms/HeapSort.c

${OBJECTDIR}/DataStructures/HeapsPrograms/OperationsOnHeap.o: DataStructures/HeapsPrograms/OperationsOnHeap.c
	${MKDIR} -p ${OBJECTDIR}/DataStructures/HeapsPrograms
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DataStructures/HeapsPrograms/OperationsOnHeap.o DataStructures/HeapsPrograms/OperationsOnHeap.c

${OBJECTDIR}/DataStructures/LinkedListPrograms/ComprehensiveLinkedList.o: DataStructures/LinkedListPrograms/ComprehensiveLinkedList.c
	${MKDIR} -p ${OBJECTDIR}/DataStructures/LinkedListPrograms
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DataStructures/LinkedListPrograms/ComprehensiveLinkedList.o DataStructures/LinkedListPrograms/ComprehensiveLinkedList.c

${OBJECTDIR}/DataStructures/LinkedListPrograms/DoublyLinkedList.o: DataStructures/LinkedListPrograms/DoublyLinkedList.c
	${MKDIR} -p ${OBJECTDIR}/DataStructures/LinkedListPrograms
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DataStructures/LinkedListPrograms/DoublyLinkedList.o DataStructures/LinkedListPrograms/DoublyLinkedList.c

${OBJECTDIR}/DataStructures/RecursionPrograms/TowerOfHanoi.o: DataStructures/RecursionPrograms/TowerOfHanoi.c
	${MKDIR} -p ${OBJECTDIR}/DataStructures/RecursionPrograms
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DataStructures/RecursionPrograms/TowerOfHanoi.o DataStructures/RecursionPrograms/TowerOfHanoi.c

${OBJECTDIR}/DataStructures/StackQueuesPrograms/InfixToPostfixUsingStack.o: DataStructures/StackQueuesPrograms/InfixToPostfixUsingStack.c
	${MKDIR} -p ${OBJECTDIR}/DataStructures/StackQueuesPrograms
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DataStructures/StackQueuesPrograms/InfixToPostfixUsingStack.o DataStructures/StackQueuesPrograms/InfixToPostfixUsingStack.c

${OBJECTDIR}/DataStructures/StackQueuesPrograms/QueueUsingCircularArray.o: DataStructures/StackQueuesPrograms/QueueUsingCircularArray.c
	${MKDIR} -p ${OBJECTDIR}/DataStructures/StackQueuesPrograms
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DataStructures/StackQueuesPrograms/QueueUsingCircularArray.o DataStructures/StackQueuesPrograms/QueueUsingCircularArray.c

${OBJECTDIR}/DataStructures/StackQueuesPrograms/QueueUsingLinkedList.o: DataStructures/StackQueuesPrograms/QueueUsingLinkedList.c
	${MKDIR} -p ${OBJECTDIR}/DataStructures/StackQueuesPrograms
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DataStructures/StackQueuesPrograms/QueueUsingLinkedList.o DataStructures/StackQueuesPrograms/QueueUsingLinkedList.c

${OBJECTDIR}/DataStructures/StackQueuesPrograms/StackUsingArrays.o: DataStructures/StackQueuesPrograms/StackUsingArrays.c
	${MKDIR} -p ${OBJECTDIR}/DataStructures/StackQueuesPrograms
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DataStructures/StackQueuesPrograms/StackUsingArrays.o DataStructures/StackQueuesPrograms/StackUsingArrays.c

${OBJECTDIR}/DataStructures/StackQueuesPrograms/StackUsingLinkedList.o: DataStructures/StackQueuesPrograms/StackUsingLinkedList.c
	${MKDIR} -p ${OBJECTDIR}/DataStructures/StackQueuesPrograms
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DataStructures/StackQueuesPrograms/StackUsingLinkedList.o DataStructures/StackQueuesPrograms/StackUsingLinkedList.c

${OBJECTDIR}/DataStructures/TreesPrograms/ComprehensiveTreeProgram.o: DataStructures/TreesPrograms/ComprehensiveTreeProgram.c
	${MKDIR} -p ${OBJECTDIR}/DataStructures/TreesPrograms
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DataStructures/TreesPrograms/ComprehensiveTreeProgram.o DataStructures/TreesPrograms/ComprehensiveTreeProgram.c

${OBJECTDIR}/main.o: main.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
