cd ..
g++ -std=c++11 --pedantic-errors sources/bigram.cpp -o binary/bigram
cp binary/bigram tests/
cd tests

echo "Running Provided Testcases"

for i in {1..3}
do
    echo "Test $i"
    ./bigram < "inputs/input1_$i.txt" > "outputs/output1_$i.txt"
    diff "outputs/output1_$i.txt" "expected/output1_$i.txt"
done
