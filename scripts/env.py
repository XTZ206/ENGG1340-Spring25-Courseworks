#!usr/bin/python3
import os
import argparse

def main():
    parser = argparse.ArgumentParser(description="Create the Environmenet for the Coursework")
    parser.add_argument("type", type=str, help="The type of coursework (assignment/checkpoint)")
    parser.add_argument("number", type=int, help="The number of the coursework")
    parser.add_argument("-t", "--testcase", action="store_true", help="Whether the testcases are provided")
    
    folder_create_group = parser.add_mutually_exclusive_group(required=True)
    folder_create_group.add_argument("-g", "--general", action="store_true", help="Only create the general directories")
    folder_create_group.add_argument("-q", "--question", type=int, help="The number of questions")
    args = parser.parse_args()
    
    if args.type not in ("assignment", "checkpoint"):
        print("Invalid coursework type")
        return
    
    os.chdir(f"/home/xtz206/Development/Education/ENGG1340/") # Change to Coursework Root Directory
    coursework_filepath = f"{args.type}s/{args.type}{args.number}/"

    # Create Coursework Directory
    os.makedirs(coursework_filepath, exist_ok=True)
    os.makedirs(coursework_filepath + "resources", exist_ok=True)
    if args.type == "checkpoint":
        os.makedirs(coursework_filepath + "documents", exist_ok=True)
    if args.general:
        return
    

    # Create Question Directories
    for question_index in range(1, args.question + 1):
        question_filepath = f"{coursework_filepath}/question{question_index}/"
        os.makedirs(question_filepath + "sources", exist_ok=True) # Create Sources Directory
        os.makedirs(question_filepath + "tests", exist_ok=True) # Create Tests Directory
        if args.testcase:
            os.makedirs(question_filepath + "tests/inputs", exist_ok=True) # Create Inputs Directory
            os.makedirs(question_filepath + "tests/outputs", exist_ok=True) # Create Outputs Directory
            os.makedirs(question_filepath + "tests/expected", exist_ok=True) # Create Expected Directory
        os.makedirs(question_filepath + "distribution", exist_ok=True) # Create Distribution Directory
       

if __name__ == "__main__":
    main()