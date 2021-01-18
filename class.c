#include <stdio.h>
#include <stdlib.h>
struct node {
    struct node *prev;
    int data;
    struct node *next;
};
void insertionStart(struct node **tail,int value){
    struct node *newNode;
    newNode =(struct node *)malloc(sizeof(struct node));
    newNode->data=value;
    if(*tail==NULL){
        *tail=newNode;
        newNode->prev=newNode;
        newNode->next=newNode;
    }
    else{
        newNode->prev=*tail;
        newNode->next=(*tail)->next;
        (*tail)->next->prev=newNode;
        (*tail)->next=newNode;
    }
}
void insertionEnd(struct node **tail,int value){
    struct node *newNode;
    newNode =(struct node *)malloc(sizeof(struct node));
    newNode->data=value;
    if(*tail==NULL){
        *tail=newNode;
        newNode->prev=newNode;
        newNode->next=newNode;
    }
    else{
        newNode->next=(*tail)->next;
        newNode->prev=*tail;
        (*tail)->next->prev=newNode;
        (*tail)->next=newNode;
        (*tail)=newNode;
    }
}
void insertionMid(struct node **tail,int pos,int value){
    struct node *newNode,*ptr=*tail;
    newNode =(struct node *)malloc(sizeof(struct node));
    newNode->data=value;
    if(pos<=1)
        printf("Wrong input\n");
    else{
        while(--pos)
            ptr=ptr->next;
        printf("data - %d\n",ptr->data);
        newNode->next=ptr->next;
        newNode->prev=ptr->next->prev;
        ptr->next->prev=newNode;
        ptr->next=newNode;
    }
}
void deleteStart(struct node **tail){
    if(*tail==NULL){
        printf("Already empty\n");
        return;
    }
    struct node *remove=(*tail)->next;
    if((*tail)->next==*tail){
        printf("Remove %d \n",remove->data);
        free(remove);
        remove=NULL;
        *tail=NULL;
    }
    else{
        remove->next->prev=remove->prev;
        remove->prev->next=remove->next;
        printf("Remove %d \n",remove->data);
        free(remove);
        remove=NULL;
    }
}
void deleteEnd(struct node **tail){
    if(*tail==NULL){
        printf("Already empty\n");
        return;
    }
    struct node *remove=*tail;
    if((*tail)->next==*tail){
        printf("Remove %d \n",remove->data);
        free(remove);
        remove=NULL;
        *tail=NULL;
    }
    else{
        printf("Remove %d \n",remove->data);
        remove->prev->next=remove->next;
        remove->next->prev=remove->prev;
        (*tail)=remove->prev;
        free(remove);
        remove=NULL;
    }
}
void deleteMid(struct node **tail,int pos){
    struct node *remove=*tail;
    if(pos<1){
        printf("Wrong input\n");
        return;
    }
    while(pos--)
        remove=remove->next;
    printf("Remove %d \n",remove->data);
    remove->prev->next=remove->next;
    remove->next->prev=remove->prev;
    free(remove);
    remove=NULL;
}
void view(struct node *tail){
    struct node *ptr=tail;
    if(tail==NULL)
        printf("Empty list\n");
    else{
        printf("LIST IS \n");
        do{
            ptr=ptr->next;
            printf("%d\n",ptr->data);
        }while(ptr!=tail);
    }
}
void main(){
    struct node* tail=NULL;
    int dis ,value,pos;
    do{
        printf("1-INSERTION AT START\n2-INSERTION AT END\n3-INSERTION AT INTERMEDIATE POSITION\n4-DELETE FORM FRONT\n5-DELETE FORM END\n6-DELETE FORM INTERMEDIATE POSITION\n7-EXIT\nENTER :");
        scanf("%d",&dis);
        switch(dis){
            case 1:printf("Enter value :");
                    scanf("%d",&value);
                    insertionStart(&tail,value);
                    view(tail);
                    break;
            case 2:printf("Enter value :");
                    scanf("%d",&value);
                    insertionEnd(&tail,value);
                    view(tail);
                    break;
            case 3:printf("Enter value :");
                    scanf("%d",&value);
                    printf("Enter position :");
                    scanf("%d",&pos);
                    insertionMid(&tail,pos,value);
                    view(tail);
                    break;
            case 4:deleteStart(&tail);
                    view(tail);
                    break;
            case 5:deleteEnd(&tail);
                    view(tail);
                    break;
            case 6: printf("Enter position :");
                    scanf("%d",&pos); 
                    deleteMid(&tail,pos);
                    view(tail);
                    break;
            case 7:break;
            default :printf("Wrong input\n");
        }

    }while(dis!=7);

}