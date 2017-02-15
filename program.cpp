#include<iostream>
using namespace std;

struct  node
{
  int Key;
  int Count;
  node *Left;
  node *Right;
};

class TREE
{
  private:
    node *Tree;//��������� �� ������ ������.
    node  *Res;//��������� �� ��������� �������.
    //����� ������� � ������ (����������� ��������).
    void Search (int, node**);
    void Delete_1 (node**,node**);
  public:
    TREE() { Tree = NULL;}
    node** GetTree() {return &Tree;}
    node** GetDel() {return &Res;}
    void  BuildTree ();
    void Vyvod (node**,int);
    bool Delete (node**, node**);
    void Poisk (int);
};

int main ()
{
  setlocale(LC_ALL,"Russian"); 
  TREE A;
  int el,x1,x2=0;
  bool fl=1;
  cout<<"�������� ��������� ������ ������(������� ��-�� �� 0):"<<endl;
  A.BuildTree ();  
  A.Vyvod(A.GetTree(),0);
  while(x2!=1 && fl)
  {
   cout<<"������� ���� ��������� �������:"; 
   cin>>el;
   A.Poisk(el);
   fl=A.Delete(A.GetTree(),A.GetDel());  
   if(fl)
   {
    A.Vyvod (A.GetTree(),0);
   cout<<"1.����� 2.���������� ��������:";
   cin>>x2;
   }
  }
}



void TREE::BuildTree ()   //���������� ��������� ������ ������.
{
 int el;
 cout<<"������� ����� ������ ������: \n";
 cin>>el;
 while  (el!=0)
 { 
  Search (el,&Tree);
  cin>>el;
 }
}

void TREE::Search (int x,node **p)
//����� ����� x � �������� ������ �� ��������
//            (����������� ��������).
//*p - ��������� �� ������� ������.
{
  if  (*p==NULL)
  { // ������� � ������ ���; �������� ��.
    *p = new(node);
    (**p).Key = x;
    (**p).Count = 1;
    (**p).Left = (**p).Right = NULL;
  }
  else
  if  (x<(**p).Key) Search (x,&((**p).Left));
  else
    if  (x>(**p).Key) Search (x,&((**p).Right));
    else  (**p).Count += 1;
}

void TREE::Vyvod (node **w,int l)
//����������� ������ w �� ������ �������
//         (����������� ��������).
//*w - ��������� �� ������ ������.
{
  int i;
  if  (*w!=NULL)
  {
    Vyvod (&((**w).Right),l+1);
    for  (i=1; i<=l; i++) cout<<"   ";
    cout<<(**w).Key<<endl;
    Vyvod (&((**w).Left),l+1);
  }
}

void TREE::Poisk (int k)
// ����� ������� � ������ k � ������
//      (������������� ��������).
// Tree - ��������� �� �������� ������.
// Res  - ��������� �� ��������� �������
{
  node *p=Tree;
  if  (Tree!=NULL)
  do
  {
    if  (p->Key==k) {Res=p;return;}
    else
      {
       if  (k<p->Key) p=p->Left;
       else  p=p->Right;
      }
  }while  (p!=NULL);
  Res=p;
  return;
}

bool TREE::Delete (node **p1,node **p2)
// �������� ������� k �� ��������� ������.
// *p1 - ��������� �� ������ ������.
// *p2 - ��������� �� ��������� �������.
{
  if  (*p1==NULL) 
  {
   cout<<"\n������ ��� ������.";
   return 0;
  }
  else
  if (*p2==NULL) 
  {
   cout<<"\n������ ��� ��������� �������.";
   return 0;
  }
  else
  {
  if  ((**p2).Right==NULL || (**p2).Left==NULL) 
  {
   cout<<"������. �������� ������� ������ ����."; 
   return 0;
  }
  else  Delete_1 (&((**p2).Left),&(*p2));
  return 1;
  }
}

void TREE::Delete_1 (node **r,node **q)
{
  node *s;
  if  ((**r).Right==NULL)
  {
    (**q).Key = (**r).Key;
    (**q).Count = (**r).Count;
    *q=*r;
    s=*r;
	*r=(**r).Left;
	delete s;
  }
  else  Delete_1 (&((**r).Right),q);
}

