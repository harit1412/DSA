int length1(SinglyLinkedListNode* head){
    int l=0;
    while (head!=NULL)
    {
        l++;
        head=head->next;
    }
    return l;
}

int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
  int len1=length1(head1);
    int len2=length1(head2);
    int d=0;
    SinglyLinkedListNode* p1;
    SinglyLinkedListNode* p2;
    if(len2>len1){
        d=len2-len1;
        p1=head2;
        p2=head1;
    }
    else{
          d=len1-len2;
          p1=head1;
          p2=head2;
    }
    while (d)
    {
        p1=p1->next;
        d--;
    }
    while (p1!=NULL && p2!=NULL)
    {
        if(p1==p2){
              return p1->data;
        }
        p1=p1->next;
        p2=p2->next;
    }
     return 0;
}