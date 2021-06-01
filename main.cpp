#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <cstring>
#include <algorithm>
#include "movies.h"

using namespace std;

bool parseLine(string &line, string &movieName, double &movieRating);

int main(int argc, char** argv){
  if(argc < 4){
    cerr << "Usage: " << argv[ 0 ] << "arg1 arg2 arg3" << endl;
    exit(1);
  }

  bool flag = false;
  if(strcmp(argv[1], "true") == 0){
    flag = true;
  } else if(strcmp(argv[1], "false") == 0) {
    flag = false;
  } else {
    cerr << "Argument 1 must be a boolean (true/false)" << endl;
    exit(1);
  }
  
  ifstream movieFile (argv[2]);
  string line, movieName;
  double movieRating;

  if (movieFile.fail()){
    cerr << "Could not open file " << argv[2];
    exit(1);
  }

  // Create an objects of the BST class you defined 
  // to contain the name and rating in the input file
  BST mytree;
  int count(1);
  // Read each file and store the name and rating
  if (!flag){
    ofstream myfile;
    myfile.open ("a.txt");
    myfile << "Nodes count: Nodes visited:" << endl;
    while (getline (movieFile, line) && parseLine(line, movieName, movieRating)){
      Node* movie1 = new Node(movieName, movieRating);
      mytree.insert(movie1);
      //Nodes visited == depth of the node
      int nodesvisited = mytree.getDepth(movie1);
      myfile << count << "\t" << nodesvisited << endl;
      count++;
      delete movie1;
    }
    myfile.close();
  }

  while (getline (movieFile, line) && parseLine(line, movieName, movieRating)){
    Node* movie1 = new Node(movieName, movieRating);
    mytree.insert(movie1);
    delete movie1;
  }

  movieFile.close();

  if (flag) { //part1
    mytree.print_preorder();
    cout << endl;
    Node* n = mytree.highest_rated(argv[3]);
    if (n) {
      cout << "Best movie is " << n->name
      << " with rating " << n->rating << endl;
    }
  }
  if (!flag) { //part2
    int arr[5];
    for (int k = 0; k<5; k++) {
      clock_t t = clock();
      for(int i=0; i< *argv[3]; i++) {
        mytree.searchforAll();
      }
      t = clock() - t;
      arr[k] = t*200000/CLOCKS_PER_SEC;
    } //t*200000 because *1000000 for microssec and /50 for argc[3] 1000000/50 = 200,000
    cout << "Times in microseconds: " << endl;
    for (int k = 0; k<5; k++) {
      cout << arr[k] << endl;
    }
  }
  return 0;
}

bool parseLine(string &line, string &movieName, double &movieRating) {
  if(line.length() <= 0) return false;
  string tempRating = "";

  bool flag = false;
  movieName = tempRating = "", movieRating = 0.0, flag = false;

  for (int i = 0; i < line.length(); i++){
    if(flag) tempRating += line[i];
    else if(line[i]==','&& line[0]!='"') flag = true;
    else {
      if(i==0 && line[0]=='"') continue;
      if(line[i]=='"'){ i++; flag=true; continue;}
      movieName += line[i];
    }
  }
  
  movieRating = stod(tempRating);
  return true;
}

