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
    Node* p = head;
    while (p != NULL) {
        cout << p->val;
        if (p->next != NULL)
            cout << ", ";
        else 
            cout << endl;
        p = p->next;
    }
}

void insertInOrder(Node* &head, int x) {
    Node* curr = head;
    if (head == NULL) {
        head = new Node(x);
        cout << head->val;
        return;
    }
    
    while (curr != NULL) {
        if (curr->val > x) {
            curr->next = new Node(x);
        } else {
            curr = curr->next;
        }
    }
}

class Leaderboard {
  public:
  Leaderboard() : scoresListHead(NULL) {}
  
  void addScore(int score) {
      insertInOrder(scoresListHead, score);
  }

  int averageScore() {
    Node* p = scoresListHead;
    int sum = 0;
    int nScores = 0;
    while (p != NULL) {
      sum += p->val;
      ++nScores;
    }

    double avg = sum / nScores;
    return avg;
  }
  
  void print() {
      printLL(scoresListHead);
  }
    private:
    Node* scoresListHead;
};


int main(int argc, const char * argv[]) {
    cout << "hello!";
    Leaderboard lboard;
    lboard.addScore(90);
    lboard.print();
    cout << endl;
    
    lboard.addScore(50);
    lboard.addScore(100);
    lboard.print();

    cout << lboard.averageScore() << endl;
    
    return 0;
}

