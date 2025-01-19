#include"header.h"


int main()
{
    printf("1. Insert into Red Black Tree\n2. Delete from Red Black Tree\n3. Search in Red Black Tree\n4. Minimum in Red Black Tree\n5. Maximum in Red Black Tree\n6. N.o of Red and Black Nodes\n7.Print(Inorder)\n8.Exit\n ");
     node*root = NULL;
     while(1)
     {
        printf("Enter option : ");
        int option;
        scanf("%d",&option);
        
        if(option==1)
        {
          printf("enter number of data u want to enter : ");
          int size;
          scanf("%d",&size);
          int arr[size];
          printf("enter tree elements : ");
          for(int i=0;i<size;i++)
          scanf("%d",arr+i);
          
          for(int i=0;i<size;i++)
            insert_rbt(&root,arr[i]); 
                    
        }
        switch(option)
        {
            
            case 2 : printf("enter data u want to delete : ");
                     int num;
                     scanf("%d",&num);
                     root = delete_node(root,num); break;
            case 3 : printf("enter number u want to search : ");
                     int num1;
                     scanf("%d",&num1);
                     int res = search(root,num1); 
                     if(res == -2)
                     printf("Tree is empty\n");
                     else if(res == -1)
                     printf("given number is not present in tree\n");
                     else{
                        printf("data is found in tree\n");
                     }
                     break;
            case 4 : if(root==NULL)
                      {
                        printf("Tree is empty\n");
                        break;
                      }
                      printf("Min : ");
                     min(root);break;
            case 5 : if(root==NULL)
                      {
                        printf("Tree is empty\n");
                        break;
                      }
                      printf("Max : ");
                     max(root);break;
            case 6 : if(root==NULL)
                      {
                        printf("Tree is empty\n");
                        break;
                      }
                      int black=0,red=0;
                      count(root,&black,&red);
                      printf("N.o Black Nodes = %d\nN.o Red Nodes = %d\n",black,red);
                      break;
            case 7 : printf("Tree elements : ");
                     inorder(root); printf("\n");
                     break;
            case 8 : return 0;
            case 9 : printf("root->val = %d\n",root->data);
        }
     }   
}
