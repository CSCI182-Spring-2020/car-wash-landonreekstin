#pragma once

enum Priority { LOW, MEDIUM, HIGH, LUDICROUS };

class Node
{
public:
	int value;
	Node* next;
	Priority nodePriority = LOW;
};

