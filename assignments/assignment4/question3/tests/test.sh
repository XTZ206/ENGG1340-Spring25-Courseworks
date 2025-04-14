cd ..
gcc -std=c11 --pedantic-errors sources/postfix.c -o binary/postfix
cp binary/postfix tests/
cd tests

echo "Running Provided Testcases"

for i in {1..3}
do
    echo "Test $i"
    ./postfix < "inputs/input3_$i.txt" > "outputs/output3_$i.txt"
    diff "outputs/output3_$i.txt" "expected/output3_$i.txt"
done
