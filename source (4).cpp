//Joanna Szewczyk

#define viu void

NODE_STRUCT* NewNode() {

	NODE_STRUCT* pointer;
	pointer = new NODE_STRUCT;

	pointer->object = new OBJECT_TYPE[SIZE];
	pointer->next = NULL;
	pointer->use = 0;

	return pointer;
}

viu DeleteNode(NODE_STRUCT* node_to_delete) {

	delete[](*node_to_delete).object;
	delete node_to_delete;

}

viu Clear(NODE_STRUCT** node) {
	NODE_STRUCT* pointer;
	pointer = *node;
	while (*node != NULL) {

		pointer = *node;
		*node = (**node).next;

		DeleteNode(pointer);
	}
	*node = NULL;
	
}

viu AddFirst(NODE_STRUCT** our_node, OBJECT_TYPE* our_object)
{

	if ((*our_node) == NULL) {
		NODE_STRUCT* our_pointer;

		our_pointer = NewNode();
		(*our_pointer).next = *our_node;
		(*our_pointer).use = 1;
		*(*our_pointer).object = *our_object;
		*our_node = our_pointer;
	}
	else {
		int i = ((**our_node).use - 1);

		if ((**our_node).use < SIZE) {

			//(**our_node).object;
			while (i >= 0) {
				*((**our_node).object + i + 1) = *((**our_node).object + i);

				i--;
			}
			*(**our_node).object = *our_object;
			(**our_node).use += 1;
		}
		else {
			NODE_STRUCT* our_pointer;

			our_pointer = NewNode();
			(*our_pointer).next = *our_node;
			(*our_pointer).use = 1;
			*(*our_pointer).object = *our_object;
			*our_node = our_pointer;
			//create a new node
		}
	}
	//our_node = NULL;
}


viu AddLast(NODE_STRUCT** our_node, OBJECT_TYPE* our_object)
{

	if ((*our_node) == NULL) {
		NODE_STRUCT* our_pointer;

		our_pointer = NewNode();
		(*our_pointer).next = *our_node;
		(*our_pointer).use = 1;
		*(*our_pointer).object = *our_object;
		*our_node = our_pointer;
	}
	else {

		NODE_STRUCT* our_pointer;
		NODE_STRUCT* our_new_pointer = *our_node;
		while ((*our_new_pointer).next != NULL) {
			our_new_pointer = (*our_new_pointer).next; //2 *?
			//pointer na ost nie jest null
		}
		if ((*our_new_pointer).use < SIZE) {
			*((*our_new_pointer).object + (*our_new_pointer).use) = *our_object;
			(*our_new_pointer).use += 1; //zostawiamy
		}
		else {
			our_pointer = NewNode();

			(*our_new_pointer).next = our_pointer;
			(*our_pointer).use = 1;
			(*our_pointer).next = NULL;
			*(*our_pointer).object = *our_object;
		}
	}
}

viu GetFirst(NODE_STRUCT* node1, NODE_STRUCT** node2, BYTE* byte) {
	if (node1 == NULL) {
		*node2 = NULL;
	}
	else {
		*node2 = node1;
		byte = 0;
	}
	
}

viu GetPrev(NODE_STRUCT* node1, NODE_STRUCT* node2, BYTE byte1, NODE_STRUCT** node3, BYTE* byte2) {
	if (byte1 == 0) {
		if (node2 == node1) {
			*node3 = NULL;
		}
		else {
			*node3 = node1;
			while ((*node1).next != node2) {
				node1 = (*node1).next;
				*node3 = node1;
			}
			*byte2 = (**node3).use - 1;
		}

	}
	else {
		*node3 = node2;
		*byte2 = (byte1 - 1);
	}

}
viu GetLast(NODE_STRUCT* node1, NODE_STRUCT** node2, BYTE* byte);
viu GetNext(NODE_STRUCT* node1, NODE_STRUCT* node2, BYTE byte1, NODE_STRUCT** node3, BYTE* byte2) {
	NODE_STRUCT* stupid;
	BYTE stupider;

	GetLast(node1, &stupid, &stupider);
	if (stupid == node2 && stupider == byte1) {
		*node3 = NULL;
	}
	else {
		while (stupid != node2 || stupider != byte1) {
			*node3 = stupid;
			*byte2 = stupider;
			GetPrev(node1, stupid, stupider, &stupid, &stupider);
		}
	}
}

viu GetLast(NODE_STRUCT* node1, NODE_STRUCT** node2, BYTE* byte) {
	int i = 0;
	if (node1 == NULL) {
		*node2 = NULL;
	}
	else {
		*node2 = node1;
		while ((**node2).next != NULL) {
			*node2 = (**node2).next;
		}
		*byte = ((**node2).use -1);
	}


}

viu RemoveCurrent(NODE_STRUCT** point_to_node, NODE_STRUCT* node, BYTE byte);

viu RemoveFirst(NODE_STRUCT** node) {
	if (*node != NULL) {
		RemoveCurrent(node, *node, 0);
	}
}

viu RemovePrev(NODE_STRUCT** node1, NODE_STRUCT* node2, BYTE byte) {
	NODE_STRUCT* nodzik;
	BYTE bycik;
	GetPrev(*node1, node2, byte, &nodzik, &bycik);
	if (nodzik != NULL) {
		RemoveCurrent(node1, nodzik, bycik);
	}
}

viu RemoveNext(NODE_STRUCT* node1, NODE_STRUCT* node2, BYTE byte) {
	NODE_STRUCT* nodzik;
	BYTE bycik;
	GetNext(node1, node2, byte, &nodzik, &bycik);
	if (nodzik != NULL) {
		RemoveCurrent(&node1, nodzik, bycik);
	}
}

viu RemoveCurrent(NODE_STRUCT** point_to_node, NODE_STRUCT* node, BYTE byte) {
	//kiedy node do usuwania jest rowne node wskazywanemu
	if ((*node).use == 1) {
		NODE_STRUCT* pointer;
		pointer = *point_to_node;
		if (node == pointer) {
			pointer = (*pointer).next;
			*point_to_node = pointer;
			DeleteNode(node);
		}
		else {
			while ((*pointer).next != node) {
				pointer = (*pointer).next;

				//usuwamy tablice
			}
			(*pointer).next = (*(*pointer).next).next;
			DeleteNode(node);
		}
	}
	else {
		//usuwamy element z object
		int i = byte;
		(*node).use -= 1;
		while (i < (*node).use) {
			*((*node).object + i) = *((*node).object + i + 1);
			i++;
		}
	}
}

viu RemoveLast(NODE_STRUCT** node) {
	NODE_STRUCT* end_node;
	BYTE byte;

	if (*node != NULL) {
		GetLast(*node, &end_node, &byte);
		RemoveCurrent(node, end_node, byte);
	}
}
void Find(NODE_STRUCT* node1, OBJECT_TYPE* object, NODE_STRUCT** node2, BYTE* byte) {

	BYTE i = 0;
	int k = 0;
	while
		(node1 != NULL) {
		i = 0;
		while (i < (*node1).use) {

			if (*((*node1).object + i) == *object) {
				*node2 = node1;
				*byte = i;
				k = 1;
				break;
			}
			i++;
		}
		if (k == 1) {
			break;
		}
		node1 = (*node1).next;
	}
	if (k != 1) {
		*node2 = NULL;
	}
}

void AddAtTheEnd(NODE_STRUCT* node, OBJECT_TYPE* object) {
	*(node->object + node->use) = *object;
	node->use += 1;
}
void AddAtTheBeggining(NODE_STRUCT* node, OBJECT_TYPE* object) {
	BYTE i = node->use;
	while (i > 0) {
		*(node->object + i + 1) = *(node->object + i);
	}
	*(node->object) = *object;
	node->use += 1;
}

void InsertPrev(NODE_STRUCT** node1, NODE_STRUCT* node2, BYTE byte, OBJECT_TYPE* object)
{
	if (node1 != NULL && node2 != NULL && object != NULL && byte < node2->use)
	{
		if (node2->use < SIZE)
		{
			if (node2->use < SIZE && byte <= node2->use && node2 != NULL && byte < SIZE)
			{
				if (node2->use > 0)
				{
					for (BYTE i = node2->use; i >= byte + 1; i--)
					{
						*(node2->object + i) = *(node2->object + i - 1);
					}
				}

				*(node2->object + byte) = *object;
				node2->use++;
			}

			return;
		}

		NODE_STRUCT* prev;
		if (*node1 == NULL)
		{
			prev = NULL;
		}
		else
		{
			NODE_STRUCT* temp = *node1;

			while (temp->next != node2 && temp->next != NULL)
			{
				temp = temp->next;
			}

			if (temp->next == NULL)
			{
				prev = NULL;
			}
			else
			{
				prev = temp;
			}
		}

		if (prev == NULL || prev->use >= SIZE)
		{
			NODE_STRUCT* current = NewNode();
			current->next = node2;

			if (prev == NULL)
			{
				*node1 = current;
				prev = current;
			}
			else
			{
				prev->next = current;
				prev = current;
			}
		}

		if (byte == 0)
		{
			if (prev != NULL && prev->use < SIZE)
			{
				if (prev->use > 0)
			{
				for (BYTE i = prev->use; i >= prev->use + 1; i--)
				{
					*(prev->object + i) = *(prev->object + i - 1);
				}
			}

			*(prev->object + prev->use) = *object;
			prev->use++;
			}
			return;
		}

		if (prev != NULL && prev->use < SIZE)
		{

			if (prev->use > 0)
			{
				for (BYTE i = prev->use; i >= prev->use + 1; i--)
				{
					*(prev->object + i) = *(prev->object + i - 1);
				}
			}
			*(prev->object + prev->use) = *node2->object;
			prev->use++;

			for (BYTE i = 1; i <= byte - 1; i++)
			{
				*(node2->object + i - 1) = *(node2->object + i);
			}

			*(node2->object + byte - 1) = *object;
		
		}

	}

}

void Compress(NODE_STRUCT* node)
{
	if (node == NULL) return;
	NODE_STRUCT* current = node;
	while (current != NULL)
	{
		if (current->use < SIZE)
		{
			int remaining = SIZE - current->use;
			NODE_STRUCT* temp = current->next;
			while (remaining > 0 && temp != NULL)
			{
				int to_move = remaining;
				if (to_move > temp->use) {
					to_move = temp->use;
				}
				for (int i = 0; i < to_move; i++)
				{
					*(current->object + current->use + i) = *(temp->object + i);
				}
				current->use += to_move;
				remaining -= to_move;
				temp->use -= to_move;
				for (int i = 0; i < temp->use; i++)
				{
					*(temp->object + i) = *(temp->object + i + to_move);
				}
				if (temp->use == 0)
				{
					current->next = temp->next;
					DeleteNode(temp);
				}
				temp = current->next;
			}
		}
		current = current->next;
	}
}



void InsertNext(NODE_STRUCT* node1, NODE_STRUCT* node2, BYTE byte, OBJECT_TYPE* object)
{
	if (node1 != NULL && node2 != NULL && object != NULL && byte < node2->use)
	{

		if (node2->use < SIZE)
		{
			if (node2 != NULL && byte + 1 < SIZE && node2->use < SIZE && byte + 1 <= node2->use)
			{

				if (node2->use > 0)
				{
					for (BYTE i = node2->use; i >= byte + 2; i--)
					{
						*(node2->object + i) = *(node2->object + i - 1);
					}
				}

				*(node2->object + byte + 1) = *object;
				node2->use++;
			}

			return;
		}

		if (node2->next == NULL || node2->next->use >= SIZE)
		{
			NODE_STRUCT* current = NewNode();
			current->next = node2->next;
			node2->next = current;
		}

		if (byte == node2->use - 1)
		{
			if (node2->next != NULL && 0 < SIZE && node2->next->use < SIZE && 0 <= node2->next->use)
			{
				if (node2->next->use > 0) {
					for (BYTE i = node2->next->use; i >= 0 + 1; i--)
					{
						*(node2->next->object + i) = *(node2->next->object + i - 1);
					}
				}
				*(node2->next->object + 0) = *object;
				node2->next->use++;
			}

			return;
		}

		if (node2->next != NULL && 0 < SIZE && node2->next->use < SIZE && 0 <= node2->next->use)
		{
			if (node2->next->use > 0)
			{
				for (BYTE i = node2->next->use; i >= 0 + 1; i--)
				{
					*(node2->next->object + i) = *(node2->next->object + i - 1);
				}
			}

			*(node2->next->object + 0) = *(node2->object + node2->use - 1);
			node2->next->use++;

			node2->use--;

			if (node2 != NULL && byte + 1 < SIZE && node2->use < SIZE && byte + 1 <= node2->use)
			{
				if (node2->use > 0)
				{
					for (BYTE i = node2->use; i >= byte + 2; i--)
					{
						*(node2->object + i) = *(node2->object + i - 1);
					}
				}
				*(node2->object + byte + 1) = *object;
				node2->use++;
			}

		}

	}
}
void Reverse(NODE_STRUCT* node)
{
	if (node == NULL)
	{
		return;
	}
	

	NODE_STRUCT* node_help = node;
	BYTE byte = 0;

	while (node_help != NULL)
	{
		for (BYTE i = 0, j = node_help->use - 1; i < node_help->use / 2; i++, j--)
		{
			OBJECT_TYPE temp = *(node_help->object + i);
			*(node_help->object + i) = *(node_help->object + j);
			*(node_help->object + j) = temp;
		}

		node_help = node_help->next;
	}

	BYTE i = 0;
	NODE_STRUCT* temp_node = node;
	while (temp_node->next != NULL)
	{
		i++;
		temp_node = temp_node->next;
	}

	NODE_STRUCT* temp_node2 = node;
	temp_node = node;

	for (BYTE j = 0; j < i /2 +1; j++)
	{
		temp_node2 = node;
		for (BYTE k = 0; k < i - j; k++)
		{
			temp_node2 = temp_node2->next;
		}

		NODE_STRUCT* temp_node3 = NewNode();
		for (BYTE k = 0; k < temp_node2->use; k++)
		{
			*(temp_node3->object + k) = *(temp_node->object + k);
			*(temp_node->object + k) = *(temp_node2->object + k);
			*(temp_node2->object + k) = *(temp_node3->object + k);
		}
		DeleteNode(temp_node3);
		temp_node->use = temp_node2->use;
		temp_node = temp_node->next;
	}
	 
Compress(node);

}