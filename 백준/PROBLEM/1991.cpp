#include <iostream>
#include <map>
using namespace std;
map<char, pair<char, char> > tree;
void preorder(char node) {
  if(node == '.')
    return;
  cout << node;
  preorder(tree[node].first);
  preorder(tree[node].second);
}
void inorder(char node) {
  if(node == '.')
    return;
  inorder(tree[node].first);
  cout << node;
  inorder(tree[node].second);
}
void postorder(char node) {
  if(node == '.')
    return;
  postorder(tree[node].first);
  postorder(tree[node].second);
  cout << node;
}

int main() {
  int n;
  cin >> n;
  char a, b, c;
  for(int i = 0; i < n; i++) {
    cin >> a >> b >> c;
    tree[a] = make_pair(b, c);
  }
  char A = 'A';
  preorder(A);
  cout << '\n';
  inorder(A);
  cout << '\n';
  postorder(A);
  cout << '\n';

  return 0;
}