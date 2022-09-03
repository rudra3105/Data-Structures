//Practical - 8(1)


#include<stdio.h>
#include<malloc.h>
#include<string.h>
typedef struct node
{
    char info[20];
    struct node *left,*right;
}tree_type;

void search(tree_type*,char []);
int display(tree_type*);

int main()
{
      tree_type *root=NULL;
      FILE *fp;
      int i=0,ch;
      char fname[20],str[20],c;
      printf("Enter the filename : ");
      scanf("%s",fname);

      fp=fopen(fname,"r");
      while((c=getc(fp))!=EOF)
      {
        if(c==' ')
            {
                str[i]='\0';
                insert(&root,str);
                i=0;
            }
        else
        {
            str[i]=c;
            i++;
        }
    }
    fclose(fp);
do{
               printf("\n1.Display and Count\n2.search\n3.Exit\nChoice : ");
               scanf("%d",&ch);
               switch(ch)
               {
                    case 1: c=display(root);
                    printf("\n\nNumber of nodes = %d",c);
                    break;
                    case 2: printf("Enter the field to be searched: ");
                    scanf("%s",str);
                    search(root,str);
                    break;
                    case 3: break;
                    default:
                    printf("Enter the correct choice: ");
               }
          }while(ch!=3);
}
void insert(tree_type **rt,char str[20])
{
     tree_type *p;
     p=(tree_type*)malloc(sizeof(tree_type));
     if(p!=NULL)
     {
          strcpy(p->info,str);
          p->right=NULL;
          p->left=NULL;
          if(*rt==NULL)
               *rt=p;
          else
          {
                if(strcmp(str,((*rt)->info))<0)
                      insert(&((*rt)->left),str);
                else
                      insert(&((*rt)->right),str);
          }
     }
}
int display(tree_type *rt)
{
    static int c=0;
    if(rt==NULL)
    {
        return c;
    }
    else
    {
        display(rt->left);
        printf("- %s",rt->info);
        c++;
        display(rt->right);
    }
}
void search(tree_type *rt,char str[20])
{
      if(rt==NULL)
      {
          printf("NOT FOUND");
          return;
      }

      if(strcmp(str,rt->info)==0)
      {
          printf("FOUND");
          return;
      }
      else
      {
           if(strcmp(str,rt->info)<0)
                 search(rt->left,str);
           else
                 search(rt->right,str);
      }
}
