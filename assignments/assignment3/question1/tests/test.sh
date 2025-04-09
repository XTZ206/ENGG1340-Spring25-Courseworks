cd ..
g++ -std=c++11 --pedantic-errors sources/strproc.cpp -o binary/strproc
cp binary/strproc tests/
cd tests

echo "Running Provided Testcases"

for i in {1..1}
do
    echo "Test $i"
    ./strproc < "inputs/input1_$i.txt" > "outputs/output1_$i.txt"
    diff "outputs/output1_$i.txt" "expected/output1_$i.txt"
done

for i in {1..10}
do
    echo "Test Extra $i"
    ./strproc < "inputs/input1_e$i.txt" > "outputs/output1_e$i.txt"
    diff "outputs/output1_e$i.txt" "expected/output1_e$i.txt"
done
