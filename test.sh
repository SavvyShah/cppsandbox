#tests the main function of provided file with the test.txt in the same folder

# Check if solution.txt and test.txt exists
if [ ! -f solution.txt ]; then
	echo "Solution.txt not found in root"
	exit
fi
if [ ! -f test.txt ]; then 
	echo "Test.txt not found in root"
	exit
fi


first=${1:-main.cpp}
expected=$(cat solution.txt)
actual=$(g++ $first && ./a.out < ./test.txt)

# Check if solution matches the output
if [ "$expected" = "$actual" ]; then
	echo -e "\e[32mTests passed\e[0m"
else
	echo -e "\e[31mTests failed\e[0m"
  echo "-------Expected--------"
  echo "$expected"
  echo "-----------------------"
  echo "-------Actual----------"
  ./a.out < ./test.txt
  echo "-----------------------"
fi
