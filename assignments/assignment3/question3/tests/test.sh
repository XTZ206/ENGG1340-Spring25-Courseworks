cd ..
g++ -std=c++11 --pedantic-errors sources/courses.cpp -o binary/courses
cp binary/courses tests/
cd tests

echo "Running Provided Testcases"

for i in {1..1}
do
    echo "Test $i"
    ./courses < "inputs/input3_$i.txt" > "outputs/output3_$i.txt"
    diff "outputs/output3_$i.txt" "expected/output3_$i.txt"
done

echo "Running Extra Testcases"

for i in {1..10}
do
    echo "Test Extra $i"
    ./courses < "inputs/input3_e$i.txt" > "outputs/output3_e$i.txt"
    diff "outputs/output3_e$i.txt" "expected/output3_e$i.txt"
done
