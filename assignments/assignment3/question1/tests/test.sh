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

echo "Running Hand-written Testcases"

for i in {1..3}
do
    echo "Test Hand-written $i"
    ./strproc < "inputs/input1_h$i.txt" > "outputs/output1_h$i.txt"
    diff "outputs/output1_h$i.txt" "expected/output1_h$i.txt"
done

echo "Running Extra Testcases"

for i in {1..20}
do
    echo "Test Extra $i"
    ./strproc < "inputs/input1_e$i.txt" > "outputs/output1_e$i.txt"
    diff "outputs/output1_e$i.txt" "expected/output1_e$i.txt"
done
