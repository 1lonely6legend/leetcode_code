#include <vector>
using namespace std;
class Solution {
 public:
  int score(const vector<int> &player) {
    int res = 0;
    for (int i = 0; i < player.size(); i++) {
      if ((i > 0 && player[i - 1] == 10) || (i > 1 && player[i - 2] >= 10)) {
        res += 2 * player[i];
      } else {
        res += player[i];
      }
    }
    return res;
  }

  int isWinner(vector<int>& player1, vector<int>& player2) {
    int s1 = score(player1);
    int s2 = score(player2);
    return s1 == s2 ? 0 : s1 > s2 ? 1 : 2;
  }
};
int main() {
  vector<int> test1 = {10,2,2,3};
  vector<int> test2 = {3,8,4,5};
  Solution S;
  auto res = S.isWinner(test1, test2);

  return 0;
}