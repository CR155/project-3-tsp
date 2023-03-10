# project-3-tsp
Project 3 - Traveling Salesperson Problem

 

Background

A very famous graph/permutation problem is the Traveling Salesperson Problem: given n cities with different distances among them and a designated first city, what is the least cost to visit all cities and return to the first one? Unfortunately, the brute-force method of solving this problem requires that we assess (n - 1)! permutations of the cities. How feasible is this?

 

However, not all is lost. For computationally "hard" problems such as this one, we may employ any of several means to find a good if not strictly optimal solution - say to within 5-10%  of the optimal solution. ("Computationally hard" problems are formally categorized as "NP-complete" or "NP-hard.") One simplified approach is based on the permutation form of genetic algorithms. Wikipedia has some good information on this technique.

 

Wikipedia link: https://en.wikipedia.org/wiki/Genetic_algorithmLinks to an external site.

 

Here is the basic approach (based upon an algorithm presented at Wikipedia) to solve our problem:

 

Choose the initial populationLinks to an external site. of tours (generate a set of permutations of the orderings of the cities)
Evaluate the fitnessLinks to an external site. (cost) of each individualLinks to an external site. tour
Repeat
Select best-ranking individuals (see Wikipedia link on "Reproduce"Links to an external site.) as elites (see below)
Create additional tours through crossover, mutation or both (genetic operations) and give birth to offspring
See Wikipedia links on BreedLinks to an external site., GenerationLinks to an external site., Crossover genetic algorithmLinks to an external site., Mutation genetic algorithmLinks to an external site., OffspringLinks to an external site.
Add new permutations to fill out the current generation
Evaluate the fitness of each individual tour
       Until termination criteria are met

 

Subsequent Generations might be made up of:

 

Mutations:

Make a minor change (for instance, randomly swap two, three, or four cities) to make a different version of an already good order.

 

Crossovers:

Splice the end of one ordering to the end of another. This is not simple to realize with permutation problems (why?)

 

Elites

Keep the few best tours as-is.

Make copies of them and mutate the copies.

 

Termination of the Algorithm:

You will repeat the process of creating a generation of tours, checking for the best, determining elites and creating mutations, until the program reaches a terminating condition. Typical ways to terminate this type of algorithm include:
A solution is found that satisfies minimum criteria (found a tour that is less than some maximum acceptable cost)
A fixed number of generations is reached.
More iterations do not produce better results
Use the fixed number of generations approach for this project.

 

Program Description

Your task in this assignment will be to write two solutions to the TSP problem, both of which will run in one program:

a brute-force permutation program that systematically tries all possible permutations, ultimately computing the optimal answer.

a genetic algorithm-inspired solution.

Program Inputs

The program will utilize an input file named distances.txt Download distances.txtwhich contains the weights of the edges between cities. You will read distances.txt Download distances.txt. For simplicity, we will deal with a problem in which all cities connect to all other - in other words, with a complete graph. We will set up a single graph that can be used for 20 cities, more than we will need for this project. You will ALWAYS just read all values of the distances into a 20 X 20 adjacency matrix. Please note that for the provided data, the adjacency matrix is not symmetric. (So the "distance" from one city to another is not necessarily the same in the opposite direction.)
 

distances.txt Download distances.txt contains the appropriate number of distances between cities (380), one per line. Note - the number of items in the file is 380 rather than 400 because no cities connect to themselves. Read them as doubles. 



When your program runs, it will interactively get the following information from the user:

the number of cities to run

how many individual tours are in a given generation

how many generations to run
what percentage of a generation should be comprised of mutated tours

Your program will always keep one elite. The program reads the distances.txt Download distances.txtfile, gets the input from the user and then the two algorithms will grind away until output is produced.

 

A graphical representation of how the generations should work is available in the following PDF:

Project3TSPGraphic.pdf

 

Getting tours to try.

You can generate permutations using the following iterative permutation algorithm:


  void perm1(int permsThisCall) 
  {
     int m, k, p , q, i;
     printS();
     permsThisCall = factorial(permsThisCall);
     for(i = 1; i < permsThisCall; i++)
     {
       m = NUMELEMENTS-2;
       while(s[m]>s[m+1])
       {
          m = m - 1;
       }
       k = NUMELEMENTS-1;
       while(s[m] > s[k])
       {
          k = k - 1;
       }
       swap(m,k);
       p = m + 1;
       q = NUMELEMENTS-1;
       while( p < q)
       {
         swap(p,q);
         p++;
         q--;
       }
       printS();
     }
   } 
Notes on the algorithm:

The algorithm as presented will produce all permutations of NUMELEMENTS ints in the s array if the following is met

int s[] // an int array external to the function
NUMELEMENTS is the number of ints in the s array that you are permuting
the parameter permsThisCall is NUMELEMENTS
you must implement swap so that the state of s is maintained
function printS() prints the s array, thereby displaying the next permutation.
If permsThisCall is fewer that NUMELEMENTS you will get just that amount of permutations, for instance when you are filling out a generation in the genetic algorithm.

 

The following C++ file demonstrates the permutation method given above:

permutations.cppDownload permutations.cpp

 

Experiments:

You will experiment with various values for these parameters to see which provide the best results for a given number of generations. You will incorporate timer capabilities into the programs so that you know how long runs with various parameters took. You will compare performance of the two approaches for different numbers of cities.

 

Start at 10 cities and go up by 1 from there until you see a runtime of greater than 5 minutes on the brute force solution. You will not have to go far to get there. Create a table that compares the time results from the approximation compared to the brute force from 10 cities up until the brute force method requires more than 5 minutes. Show what percentage of the optimal solution (eg: 120% of optimal) your approximation solution provides at each run.

 

A Timer:

Here is a link to the file: time.cDownload time.c

 

Output:

When the progam runs, it will display as output:

The number of cities run
optimal cost from brute force
time the brute force algorithm took
cost from the genetic algorithm
time the genetic algorithm took to run
percent of optimal (eg: 120%) that the genetic algorithm produced 
 

Deliverables

You will submit the following for this project:

1. A User's manual that describes how to set up and run your program.

2. A UML diagram reflecting the final layout of your program.

3. Your source code in C++.
4. Results file: An Excel spreadsheet containing the results from each run (for 10, 11, 12, etc cities) with one row for the 10 city, 11 city, 12 city, etc run. The column headers should be the 6 items output by a single run. This table is a summary of the data for all the individual  outputs from 10 cities, 11 cities, etc.

5. A makefile for the project

 

 Submission Requirements:  

Note: you will lose 10% if you do not follow these instructions exactly. The reason for this policy is that eLearning puts zip files inside zip files and it is a time-consuming, tedious, and error-prone policy to unzip them all one-by-one. I have a utility I wrote that nicely unzips all these into a usable folder structure. If you do not follow these instructions, your files will get all mashed up together with others, often with name collisions and it is an unusable mess.

1. Compile and run your program one last time before submitting it. Your program must run in Linux in the multiplatform lab. 

2. Place all deliverables in a single folder that is named with your last name and first name initial. For example, if your name is Katie Brodhead, the folder should be brodheadk. If you are a MacOS user, delete the _MacOS_ folder before zipping up your submission.

3. Create a "zip"  file using WinZip or similar program that creates .zip files, to hold your project files.

Your zip file should be named exactly like the single folder inside it but with the .zip extension. For instance: brodheadk.zip.

3. Login to Canvas and select our course from the dashboard.

4. Go to the Assignments page and choose the assignment for which you are submitting a project.

5. Click the "Submit Assignment" button.
6. Use the "Choose File" capability to select and upload your .zip file.
Please review the policy on ACADEMIC MISCONDUCT. This is an individual assignment.
