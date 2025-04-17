cd ..
gcc -std=c11 --pedantic-errors sources/runlen.c -o binary/runlen
cp binary/runlen tests/
cd tests

echo "Running Provided Testcases"

for i in {1..3}
do
    echo "Test $i"
    ./runlen < "inputs/input2_$i.txt" > "outputs/output2_$i.txt"
    diff "outputs/output2_$i.txt" "expected/output2_$i.txt"
done

echo "Running Extra Testcases"
for i in {1..10}
do
    echo "Test Extra $i"
    ./runlen < "inputs/input2_e$i.txt" > "outputs/output2_e$i.txt"
    diff "outputs/output2_e$i.txt" "expected/output2_e$i.txt"
done
