#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
  //走完以下两个判断。确保两个链表皆不为空
  if (l1 == nullptr) return l2;
  if (l2 == nullptr) return l1;

  ListNode *ans = new ListNode(0);//初始化返回节点
  ListNode *p1 = l1, *p2 = l2, *p3 = ans;//初始化遍历指针
  //
  //关键是如果两个链表长度不相等时，将不相等的位数用0补上//
  //
  int duoyu = 0;//定义在while结构体外面，方便后续判断是否需要补位
  //就是需要进位的数，加起来是22 就进2 加起来是19 就进1

  while (p1 != nullptr || p2 != nullptr) {//循环直到两个链表都走到头
    //如果有链表走到尽头剩下的就由0来补足吧
    int val1 = p1 ? p1->val : 0;
    int val2 = p2 ? p2->val : 0;
    //这个位上的三个数的和：l1和l2链表，以及上一次循环的进位
    int sum = val1 + val2 + duoyu;
    p3->val = sum % 10;
    p3->next = new ListNode(0);
    p3 = p3->next;
    duoyu = sum / 10;
    //如果链表不空指针就往后移动
    p1 = p1 ? p1->next : p1;
    p2 = p2 ? p2->next : p2;
  }
  //结束之后p3指针指向两个列表更长的位数的下一个节点，需判断最后一次循环的进位是否为0；
  if (duoyu == 0) {
    //等于0代表无需增添进位，直接将p3置成空指针
    p3 = nullptr;
  } else {
    //不等于0，说明需要增添一位数字
    p3->val = duoyu;
  }
  return ans;
}

int main() {
  int num1[3] = {2, 4, 3};
  int num2[3] = {5, 6, 4};
  ListNode *l1 = new ListNode(0);
  ListNode *l2 = new ListNode(0);
  ListNode *p1 = l1, *p2 = l2;

  p1->val = 2;
  p1->next = new ListNode(4);
  p1->next->next = new ListNode(3);

  p2->val = 5;
  p2->next = new ListNode(6);
  p2->next->next = new ListNode(4);

  ListNode *ans = addTwoNumbers(l1, l2);
  ListNode *p3 = ans;
  while (p3) {
    std::cout << p3->val;
    p3 = p3->next;
  }
  return 0;
}
