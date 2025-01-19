#include"header.h"


node*checkfordb(node*root,node*temp)
{
    node*remove_element = temp;
    //printf("%d  temp->parent : %d\n",temp->data,temp->parent->data);
    int n=2;
  while(1)
  {
    node*parent = temp->parent;
    node*sibiling ;
    if(root->colour=='D')
        {
           if(remove_element==root)
           {
               if(root->left == NULL)
               {
                   root = root->right;
                   root->right->parent = NULL;
               }
               else{
                   root = root->left;
                   root->left->parent = NULL;
               }
                 free(remove_element);
           }
           else
            root->colour='B';
            return root;
        }
    if(parent->left == temp)
    {
       
        sibiling = parent->right;
        if(sibiling!=NULL&&sibiling->colour=='B'&&((sibiling->right==NULL&&sibiling->left==NULL)||(sibiling->right!=NULL&&sibiling->left==NULL&&sibiling->right->colour=='B')||(sibiling->left!=NULL&&sibiling->right==NULL&&sibiling->left->colour=='B')||(sibiling->left!=NULL&&sibiling->right!=NULL&&sibiling->left->colour=='B'&&sibiling->right->colour=='B')))
        {
            if(parent->colour=='R')
            {
                //printf("aaaaaaa");
                parent->colour = sibiling->colour;
                sibiling->colour = 'R';
                if(temp == remove_element)
                {
                    parent->left =NULL;
                    free(temp);
                }
                else{
                   temp->colour = 'B'; 
                }
                //inorder(root);
                return root;
            }
            else{
                // printf("akshay");
                parent->colour ='D';
                sibiling->colour ='R';
                if(temp == remove_element)
                 { parent->left = NULL;
                  free(temp);}
                  else{
                      temp->colour = 'B';
                  }
                temp = parent;
            }
        }
       else if(root->colour=='D')
        {
            //printf("anjana");
            root->colour='B';
            return root;
        }
        else if(sibiling!=NULL&&sibiling->colour=='R')
        {
            //printf("onr");
           sibiling->colour = parent->colour;
            parent->colour = 'R';
            leftrotate(&root,parent);
            //inorder(root);
            //printf("\n");
           // printf("root->data : %d   root->left->right->colour %c      root->left->right->data : %d\n",root->data,root->left->right->colour,root->left->right->data);
        }
        else if(sibiling!=NULL&&sibiling->colour=='B'&&(sibiling->left!=NULL&&sibiling->left->colour == 'R'||sibiling->right!=NULL&&sibiling->right->colour=='R'))
        { 
            if(sibiling->right!=NULL&&sibiling->right->colour == 'R')//far child
            {
                char temp1 = sibiling->colour;
                sibiling->colour = parent->colour;
                parent->colour = temp1;
                leftrotate(&root,parent);
                sibiling->right->colour ='B';
                if(temp == remove_element)
                {
                    free(temp);
                    parent->left = NULL;
                }
                else
                temp->colour = 'B';
                return root;
            }
            if(sibiling->left->colour == 'R')   //near child
            {  
                sibiling->left->colour = sibiling->colour;
                sibiling->colour = 'R';
                rightrotate(&root,sibiling);
            }
        }
    }
    else{
        sibiling = parent->left;
         if(sibiling!=NULL&&sibiling->colour=='B'&&((sibiling->right==NULL&&sibiling->left==NULL)||(sibiling->right!=NULL&&sibiling->left==NULL&&sibiling->right->colour=='B')||(sibiling->left!=NULL&&sibiling->right==NULL&&sibiling->left->colour=='B')||(sibiling->left!=NULL&&sibiling->right!=NULL&&sibiling->left->colour=='B'&&sibiling->right->colour=='B')))
        {
            if(parent->colour=='R')
            {
                //printf("aaaaaaa");
                parent->colour = sibiling->colour;
                sibiling->colour = 'R';
                if(temp == remove_element)
                {
                    parent->right =NULL;
                    free(temp);
                }
                else{
                   temp->colour = 'B'; 
                }
                //inorder(root);
                return root;
            }
            else{
                // printf("akshay");
                parent->colour ='D';
                sibiling->colour ='R';
                if(temp == remove_element)
                 { parent->right = NULL;
                  free(temp);}
                  else{
                      temp->colour = 'B';
                  }
                temp = parent;
            }
        }
        else if(root->colour == 'D')
         {
            //printf("anjana");
            root->colour='B';
            return root;
        }
        else if(sibiling!=NULL&&sibiling->colour=='R')
        {
            //printf("onr");
            sibiling->colour = parent->colour;
            sibiling->colour = 'R';
            rightrotate(&root,parent);
            //inorder(root);
            //printf("\n");
            //printf("root->data : %d   root->left->right->colour %c      root->left->right->data : %d\n",root->data,root->left->right->colour,root->left->right->data);
        }
        else if(sibiling!=NULL&&sibiling->colour=='B'&&(sibiling->left->colour == 'R'||sibiling->right->colour=='R'))
        {
           
            if(sibiling->left->colour == 'R')
            {
                char temp1 = sibiling->colour;
                sibiling->colour = parent->colour;
                parent->colour = temp1;
                //printf("before rotation : ");
                 //inorder(root);
                rightrotate(&root,parent);
                //printf("\nafter rotation : ");
                // inorder(root);
                // printf("\n");
                sibiling->left->colour ='B';
                if(temp == remove_element)
                {
                    temp->parent->right = NULL;
                     free(temp);
                }
                else
                temp->colour = 'B';
                inorder(root);
                return root;
            }
             if(sibiling->right->colour == 'R')
            {
                sibiling->right->colour = sibiling->colour;
                sibiling->colour = 'R';
                leftrotate(&root,sibiling);
            }
        }
    }  
  }
}

node*delete_node(node*root,int data)
{
    if(root==NULL)
    {
        printf("List is empty\n");
        return root;
    }
    if(root->left==NULL&&root->right==NULL&&root->data==data)
    {
        return NULL;
    }
    node*temp = root,*db=NULL;
    while(temp!=NULL)
    {
        if(temp->data > data)
        temp = temp->left;
        else if(temp->data < data)
        temp = temp->right;
        else
        break;
    }
    if(temp==NULL)
    {
        printf("entered data not found \n ");
        return root;
    }
    node* target = temp;
    char target_colour  = temp->colour;
    if(temp->left==NULL&&temp->right==NULL)
    {
        if(temp->parent->right == temp)
        {
            if(temp->colour == 'B')
             {
                temp->colour = 'D';
                target_colour = 'D';
             }
            else
            temp->parent->right = NULL;

        }
        else{
             if(temp->colour == 'B')
              {
                temp->colour = 'D';
                target_colour = 'D';
              }
            else
            {
                temp->parent->left = NULL;
                free(temp);
            }
        }
        
    }
    else if(temp->left == NULL)
    {
        temp->data = temp->right->data;
        db = temp->right;
        if(temp->right->colour == 'B')
         {
             temp->right->colour = 'D';
             target_colour ='D';
             temp = temp->right;
         }
        else
        {
            temp->right = NULL;
            free(db);
        }
    }
     else if(temp->right == NULL)
    {
       temp->data = temp->left->data;
       db = temp->left;
       if(temp->left->colour == 'B')
        {
            temp->left->colour = 'D';
            target_colour = 'D';
            temp = temp->left;
        }
        else
        {
            temp->left = NULL;
            free(db);
        }
    }
    else{
           node*succ = get_min(temp->right);
           //printf("akshay");
         // printf("succ->data : %d\n",succ->data);
           if(succ->right==NULL)
           {
            temp->data = succ->data;
            target_colour = succ->colour;
            if(succ->colour=='B')
            {
                succ->colour = 'D';
                target_colour ='D';
                temp = succ;
            }
            else
            {
                succ->parent->right = NULL;
                free(succ); 
           }
          }
           else{
            temp->data = succ->data;
            succ->data = succ->right->data;
            target_colour = succ->right->colour;
              if(succ->right->colour=='B')
              {
                succ->right->colour = 'D';
                target_colour = 'D';
                temp = succ->right;
              }
              else
              {
                  free(succ->right);
                 succ->right = NULL;
              }
             
           }
    }
   
   if(target_colour == 'D')
    root = checkfordb(root,temp);
   // printf("temp->data : %d   temp->parent->data%d\n",temp->data,temp->parent->data);
     //free(temp);
     printf("delete operation successful\n");
    return root;

}
