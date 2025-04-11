cd ..
g++ -std=c++11 --pedantic-errors sources/route.cpp -o binary/route
cp binary/route tests/
cd tests

echo "Running Provided Testcases"

for i in {1..1}
do
    echo "Test $i"
    echo "inputs/input2_$i.txt" | ./route > "outputs/output2_$i.txt"
    diff "outputs/output2_$i.txt" "expected/output2_$i.txt"
done

echo "Running Self-Writing Testcases"

for i in {1..1}
do 
    echo "Test Self-Writing $i"
    echo "inputs/input2_s$i.txt" | ./route > "outputs/output2_s$i.txt"
    diff "outputs/output2_s$i.txt" "expected/output2_s$i.txt"
done
