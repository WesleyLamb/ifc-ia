#include <stdio.h>
#include <stdlib.h>

struct Node;

typedef struct {
    Node from;
    Node to;
    int length;
} Link;

typedef struct {
    char name;
    Link* links;
    int linkCount;
} Node;

Node* montarArvore();
Node* criarNode(char aName);
void criarLink(Node* aStartingNode, Node* anEndingNode, int aLength);

int main()
{
    *Node tree = montarArvore()


    return 0;
}

Node *montarArvore()
{
    char names[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u'};
    Node** aNode = malloc(sizeof(Node) * 21);
    for(int i = 0; i < 21; i++) {
        aNode[i] = criarNode(names[i]);
    }

    // A
    criarLink(aNode[0], aNode[2], 3);

    // B
    criarLink(aNode[1], aNode[2], 2);
    criarLink(aNode[1], aNode[3], 3);

    // C
    criarLink(aNode[2], aNode[0], 2);
    criarLink(aNode[2], aNode[1], 2);
    criarLink(aNode[2], aNode[6], 2);

   // D
   criarLink(aNode[3], aNode[1], 2);
   criarLink(aNode[3], aNode[4], 2);

   // E
   criarLink(aNode[4], aNode[3], 2);
   criarLink(aNode[4], aNode[5], 3);

   // F
   criarLink(aNode[5], aNode[4], 2);
   criarLink(aNode[5], aNode[9], 3);

   // G
   criarLink(aNode[6], aNode[2], 3);
   criarLink(aNode[6], aNode[7], 3);
   criarLink(aNode[6], aNode[10], 2);

    // H
    criarLink(aNode[7], aNode[6], 2);
    criarLink(aNode[7], aNode[8], 2);
    criarLink(aNode[7], aNode[10], 3);
    criarLink(aNode[7], aNode[11], 3);

    // I
    criarLink(aNode[8], aNode[7], 2);
    criarLink(aNode[8], aNode[9], 3);

    // J
    criarLink(aNode[9], aNode[5], 3);
    criarLink(aNode[9], aNode[8], 2);
    criarLink(aNode[9], aNode[12], 2);

    // K
    criarLink(aNode[10], aNode[6], 2);
    criarLink(aNode[10], aNode[7], 3);
    criarLink(aNode[10], aNode[13], 2);

    // L
    criarLink(aNode[11], aNode[7], 2);
    criarLink(aNode[11], aNode[12], 3);

    // M
    criarLink(aNode[12], aNode[9], 2);
    criarLink(aNode[12], aNode[11], 2);
    criarLink(aNode[12], aNode[15], 3);

    // N
    criarLink(aNode[13], aNode[10], 2);
    criarLink(aNode[13], aNode[14], 2);
    criarLink(aNode[13], aNode[16], 3);

    // O
    criarLink(aNode[14], aNode[13], 2);
    criarLink(aNode[14], aNode[15], 3);

    // P
    criarLink(aNode[15], aNode[14], 2);


}

Node *criarNode(char aName)
{
    Node* aNode = malloc(sizeof(Node));
    aNode->links = malloc(sizeof(Link**));

    aNode->name = aName;
    aNode->linkCount = 0;

    return aNode;
}

void criarLink(Node *aStartingNode, Node *anEndingNode, int aLength)
{
    realloc(aStartingNode->links, sizeof(Link**))

}
