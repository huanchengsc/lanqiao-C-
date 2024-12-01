#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
#include <stack>
using namespace std;


struct ListNode      //定义链表
{
	int val;
	ListNode* next;
	ListNode(int x = 0):val(x),next(nullptr) {}
	ListNode(int x,ListNode* next):val(x),next(next)  {}
};

//class Solution     //法一：递归法，注意返回值是数组，如果不转化为void，每次要接收返回值
//{
//public:
//	vector<int> reverseList(ListNode* head) {
//		reverse(head);
//		return res;
//	}
//private:
//	vector<int> res;
//	void reverse(ListNode* head) {
//		if (head == nullptr)
//			return;
//		reverse(head->next);
//		res.push_back(head->val);
//	}
//};


class Solution     //法二：辅助栈法
{
public:
	vector<int> reverseList(ListNode* head) {
		stack<int> stk;
		while (head != nullptr) {
			stk.push(head->val);
			head = head->next;
		}
		vector<int> res;
		while (!stk.empty()) {
			res.push_back(stk.top());
			stk.pop();
		}
		return res;
	}

};
int main()
{
	ListNode head(4);
	ListNode head1(3, &head);
	ListNode head2(2, &head1);
	ListNode head3(1, &head2);
	cout << "反转前" << endl;
	ListNode* p = &head3;
	while (p != nullptr)
	{
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
	Solution obj;
	vector<int> v = obj.reverseList(&head3);
	vector<int>::iterator it = v.begin();
	cout << "反转后" << endl;
	for (; it != v.end(); it++)
	{
		cout << *it << " ";
	}
	return 0;
}