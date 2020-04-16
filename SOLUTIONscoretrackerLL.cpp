// Example program
#include <iostream>
#include <string>

// DISCLAIMER: NOT MEANT AT ALL TO BE USED AN EXAMPLE FOR HOMEWORKS OR PROJECTS
// I WROTE THIS CODE IN A FEW MIN TO PURPOSELY BE BUGGY AND DOES NOT NECESSARILLY HAVE GOOD CODING STYLE

using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(NULL) {}
};

void printLL(Node* head) {
    Node* p = head; /// FIXED SEGFAULT. initialize with head
    while (p != NULL) {
        cout << p->val;
        if (p->next != NULL)
            cout << ", ";
        else 
            cout << endl;
        p = p->next;
    }
}

void insertAtFront(Node* &head, int x) {
    Node* curr = head;
    
    Node* newNode = new Node(x);
    newNode->next = head;
    head = newNode; // FIXED, we need head to point to the new head node
}

class ScoreTracker {
  public:
  ScoreTracker() : scoresListHead(NULL), nScores_(0) {}
  
  void addScore(int score) {
    insertAtFront(scoresListHead, score);
    ++nScores_; // FIXED, increment nScores_
  }

  void printStats() {
    if (nScores_ <= 0) { // FIXED > to <=
      cout << "No scores yet.\n";
      return;
    }

    double avgScore = getAverageScore();
    cout << "Average score: " << avgScore << endl;

    Node* p = scoresListHead;
    int nAboveAvg = 0;
    while (p != NULL) {
      if (p->val > avgScore) {
        ++nAboveAvg;
      }
      p = p->next;
    }
    double pctAboveAvg = (nAboveAvg * 100.0) / nScores_; // FIXED: must do double division
    cout << pctAboveAvg << "% scored above average." << endl;
  }

  double getAverageScore() {
    Node* p = scoresListHead;
    int sum = 0;
    while (p != NULL) {
      sum += p->val;
      p = p->next;
    }

    double avg = sum / nScores_;
    return avg;
  }
  
  void print() {
      printLL(scoresListHead);
  }
    private:
    Node* scoresListHead;
    int nScores_;
};


int main(int argc, const char * argv[]) {
    cout << "hello!\n";
    ScoreTracker tracker;
    tracker.addScore(97);
    tracker.print();
    cout << endl;
    
    tracker.addScore(50);
    tracker.addScore(100);
    tracker.addScore(80);
    tracker.print();

    tracker.printStats();
    
    return 0;
}

