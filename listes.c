/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jd-halle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 02:22:35 by jd-halle          #+#    #+#             */
/*   Updated: 2024/08/16 02:22:54 by jd-halle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void freeList(Liste *liste)
{
	Node *current = liste->premier;
	Node *nextNode;
	while (current)
	{
		nextNode = current->next;
        free(current);
        current = nextNode;
	}
	free(liste);
}*/
int	list_sorted(Liste *liste)
{
	Node *current;

	current = liste -> premier;
	while (current->next)
	{
		if (current -> data > current -> next->data)
		{
			ft_printf("liste non trie\n");
			return (-1);
		}
		current = current ->next;
	}
	ft_printf("liste trie\n");
	return (1);
}


int algo_tri(Liste *liste)                                    // ALGO TRI !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
{
	Liste *listeB;

	pb(liste, listeB);
	if (list_sorted(liste) == 1)
	{
		//remettre ce quon vient de push b sur sa cible dans la stack a ; le chiffre le plus grand le plus proche de lui
		while (list_sorted(liste) == -1)
		//		si le plus petit est dans la partie haute des index on fait un rotate + list_sorted? si non on refait un rotate + list_sorted?
		//		si le plus petit est dans la partie basse des index on fait un reverse rotate + list_sorted? si non on refait un reverse rotate + list_sorted?
	}
	pb(liste, listeB);
	if (list_sorted(liste) == 1)
	{
		//compter le nombre de coup pour mettre chacun des 2 nbrs de b sur sa cible dans la stack a ; le chiffre le plus grand le plus proche de lui,
		//	prendre celui qui prend le moins de coups a ranger sur a. puis ranger l autre ensuite.
		while(list_sorted(liste) == -1)
		{
			//
		}
	}
}


Liste *initialisation()
{
	Liste *liste = malloc(sizeof(*liste));
	if (liste == NULL)
		exit(EXIT_FAILURE);
	liste ->premier = NULL;
	return (liste);
}

Node *createNode(int data)
{
	Node *New = malloc(sizeof(Node));
	if (New == NULL)
	{
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
	New -> data = data;
	New -> next = NULL;
	return (New);
}
void appendNode(Liste *liste, int data)
{
	Node *newNode = createNode(data);
	if (liste -> premier == NULL)
		liste -> premier = newNode;
	else
	{
		Node *current = liste ->premier;
		while (current -> next)
			current = current -> next;
		current->next = newNode;
	}
}
Liste *fill_List(long int *tab, int countA)
{
	int i = 0;
	Liste *liste = initialisation();
	while (i < countA)
	{
		appendNode(liste, (int)tab[i]);
		i++;
	}
	return (liste);
}
void printList(Liste *liste)
{
    Node *current = liste -> premier;
    while (current != NULL)
	{
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
	//javais ca dans la fonction tri
	/*else if (countA > 3)
	{
		Liste *liste = fill_List(tab, countA);
		if (list_sorted(liste) == 1)
		{
			return (1);
		}
		//algo_tri(liste);         //on va creer lalgo de tri et il va check si liste is sorted
		printList(liste);
		freeList(liste);
	}*/

	//dans le .h 
	
	/*typedef struct Node {
    int data;
	struct Node* next;
} Node;

typedef struct Liste Liste;
struct Liste
{
    Node *premier;
};*/