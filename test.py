#tests the main function of provided file with the test.txt in the same folder
import sys
import subprocess
from pathlib import Path

solution_path = Path("solution.txt")
test_path = Path("test.txt")

if not solution_path.exists():
  print("solution.txt not found in root")
  sys.exit()

if not test_path.exists():
  print("test.txt not found in root")
  sys.exit()

first = "main.cpp"
try:
  first = sys.argv[1]
except:
  first = "main.cpp"

solution_file = open("solution.txt", "r")
test_file = open("test.txt", "r")

test = test_file.read()
expected = solution_file.read()

solution_file.close()
test_file.close()

subprocess.run(["g++", first])
actual = subprocess.run([ "./a.out"], input=test, capture_output=True, text=True)

if actual.stderr:
  print(actual.stderr)
  sys.exit()

if expected == actual.stdout:
  print("Tests passed\n")
else:
  print("Tests failed\n")
  print("-------Expected--------")
  print(expected)
  print("-------Actual----------")
  print(actual.stdout)
  print("-----------------------")
