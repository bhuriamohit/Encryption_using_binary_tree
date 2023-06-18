/*
Mohit bhuria
Mohit meena
Nitesh kumar

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

// Define the Tree Node here
struct Node {
    int value;
    // Pointers to the left and right children
    Node* left, *right;
};


Node* init_tree(int data) {
    // Creates the tree and returns the
    // root node
    Node* root = (Node*) malloc (sizeof(Node));
    root->left = root->right = NULL;
    root->value = data;
    return root;
}

Node* create_node(int data) {
    // Creates a new node
    Node* node = (Node*) malloc (sizeof(Node));
    node->value = data;
    node->left = node->right = NULL;
    return node;
}

void free_tree(Node* root) {
    // Deallocates memory corresponding
    // to every node in the tree.
    Node* temp = root;
    if (!temp)
        return;
    free_tree(temp->left);
    free_tree(temp->right);
    if (!temp->left && !temp->right) {
        free(temp);
        return;
    }
}

int tree_height(Node* root) {
    // Get the height of the tree
    if (!root)
        return 0;
    else {
        // Find the height of both subtrees
        // and use the larger one
        int left_height = tree_height(root->left);
        int right_height = tree_height(root->right);
        if (left_height >= right_height)
            return left_height + 1;
        else
            return right_height + 1;
    }
}

void print_level(Node* root, int level_no) {
    // Prints the nodes in the tree
    // having a level = level_no
    
    // We have a auxiliary root node
    // for printing the root of every
    // subtree
    if (!root)
        return;
    if (level_no == 0) {
        // We are at the top of a subtree
        // So print the auxiliary root node
        printf("%d -> ", root->value);
    }
    else {
        // Make the auxiliary root node to
        // be the left and right nodes for
        // the subtrees and decrease level by 1, since
        // you are moving from top to bottom
        print_level(root->left, level_no - 1);
        print_level(root->right, level_no - 1);
    }

}

void print_tree_level_order(Node* root) {
    if (!root)
        return;
    int height = tree_height(root);
    for (int i=0; i<height; i++) {
        printf("Level %d: ", i);
        print_level(root, i);
        printf("\n");
    }
    printf("\n\n-----Complete Level Order Traversal:-----\n");
    for (int i=0; i<height; i++) {
        print_level(root, i);
    }
    printf("\n");
}

//to track the length of message
size_t len = 0;

char *inputString(FILE *fp, size_t size)
{
    // The size is extended by the input with the value of the provisional
    char *str;
    int ch;
    str = realloc(NULL, sizeof(*str) * size); // size is start size
    if (!str)
        return str;
        //getting the pointer to the end of file
    while (EOF != (ch = fgetc(fp)) && ch != '\n')
    {
        str[len++] = ch;
        if (len == size)
        {//if size is full 
        //increasing size
            str = realloc(str, sizeof(*str) * (size += 16));
            if (!str)
                return str;
        }
    }//ending the string with
    str[len++] = '\0';
//removing the extra space asigned
    return realloc(str, sizeof(*str) * len); 
}
//function for encryption
void encrypt(void)
{
    char *m;
    printf("\nInput the message you want to encrypt: \n");
    scanf("\n");
    //calling the input function
    m = inputString(stdin, 10);
   
    //making the length even for proper pairing
    if (len % 2 != 0)
    {
        len--;
    }
    //declaring array of lenght to keep order of ascii value
    int a[len + 1];
    a[0] = 0;
    /*
    First level decryption
    step 1:Convert the characters of the intermediate message into corresponding ASCII values
    Step 2:Form pairs with the ASCII values.
    Step 3:Interchange  the ASCII values.
    */
    for (int i = 0; i < len;)
    {
        int temp = (int)m[i] + i + 2;
        a[i + 1] = temp;
        i++;
        temp = (int)m[i] + i;
        a[i + 1] = temp;
        i++;
    }
    //free the pointer as we have array of ascii
    free(m);
 //performing the level order traversal of binary tree
    for (int i = 2; i <= len;)
    {
        if (i + 1 <= len)
        {
            int d = a[i];
            a[i] = a[i + 1];

            a[i + 1] = d;
        }
        i = i + 2;
    }
    printf("\nyOUR encrypted message is:\n");
    //printing the encrypted msg
    for (int i = 1; i <= len; i++)
    {
        printf("%c", a[i]);
    }
    len=0;
}//function for decryption
void decrypt(void)
{
    char *m;

    printf("\nInput the message you want to decrypt:\n ");
    scanf("\n");
    //taking string input
    m = inputString(stdin, 10);
// removing the last character
    len--;
    //declaring array of length
    int a[len + 1];
    a[0] = 0;
    //substracting the index as per the paper
    for (int i = 0; i < len;)
    {
        int temp = (int)m[i];
        a[i + 1] = temp;
        i++;
        temp = (int)m[i];
        a[i + 1] = temp;
        i++;
    }
    //freeing the pointer
    free(m);
    //   printf("\n");
//performing the level orcer traversal of complete binary tree
    for (int i = 2; i <= len;)
    {//we can perform the traversal only if we have the next element
        if (i + 1 <= len)
        {
            int d = a[i];
            a[i] = a[i + 1];

            a[i + 1] = d;
        }
        //jump 2 index ahead
        i = i + 2;
    }
   
    //substracting the index pf paired characters
    for (int i = 1; i <= len;)
    {
        int temp = a[i];
        a[i] = temp - i - 1;

        temp = a[i + 1];
        a[i + 1] = temp - i;
        i++;
        i++;
    }
    printf("\nyOUR decrypted message is:\n");
    for (int i = 1; i <= len; i++)
    {
        printf("%c", a[i]);
    }
    len=0;
}
int main(void)
{
    
   while(1) {char c;
   

        printf("\n1. To encrypt\n2. to decrypt\n3. quit");

        printf("\nEnter the choice(1 or 2 or 3)\n");

        scanf("\n%c", &c);
        
        if (c == '1')
        {
            encrypt();
        }
        else if (c == '2')
        {
            decrypt();
    printf("\n");
        }
        else if (c=='3')
        {
            printf("\nQuited.....\n");
            return 0;
        }
        else {
            printf("Please enter a right choice");
        }}
         return 0;
        }
       
   
