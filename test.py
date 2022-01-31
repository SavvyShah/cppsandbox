#tests the main function of provided file with the test.txt in the same folder
import sys
import subprocess
from pathlib import Path
#timeout(in seconds): Timeout after which if the subprocess is still running kill it. Adjust it as per need.
TIMEOUT = 10

def printError(line):
  print("\033[91m{}\033[00m\n".format(line))

def printSuccess(line):
  print("\033[92m{}\033[00m\n".format(line))

solution_path = Path("solution.txt")
test_path = Path("test.txt")

if not solution_path.exists():
  print("solution.txt not found in root")
  sys.exit()

if not test_path.exists():
  print("test.txt not found in root")
  sys.exit()

first = "main.cpp"
second = ""
if len(sys.argv) > 1:
  first = sys.argv[1]
if len(sys.argv) > 2:
  second = sys.argv[2]

solution_file = open("solution.txt", "r", encoding="utf-8")
test_file = open("test.txt", "r", encoding="utf-8")

test = test_file.read()
expected = solution_file.read()

solution_file.close()
test_file.close()

subprocess.run(["g++", first])
try:
  actual = subprocess.run([ "./a.out"], timeout=TIMEOUT, input=test, capture_output=True, text=True)
  if actual.stderr:
    print(actual.stderr)
    sys.exit()
  elif expected == actual.stdout:
    printSuccess("Tests passed")
  else:
    printError("Tests failed")
    print("-------Expected--------")
    print(expected)
    print("-------Actual----------")
    print(actual.stdout)
    print("-----------------------")
except subprocess.TimeoutExpired:
    printError("Timelimit exceeded")
    sys.exit()
