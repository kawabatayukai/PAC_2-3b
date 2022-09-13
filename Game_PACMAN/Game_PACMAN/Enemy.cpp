#include <stdio.h>
#include <memory.h>
#include <list>
#include <queue>
#include <vector>
#include <math.h>
#include "Info.h"
#include "Stage.h"

//const int MapWidth = 5;
//const int MapHeight = 5;
const int Infinity = 100000;

// �폜����
enum EraseResult
{
	NotFound,		// ������
	Erased,			// �폜
	CouldntErased	// �폜�ł��Ȃ�
};

// Map�̃}�X��
struct Cell
{
	Cell() :
		X(-1),
		Y(-1)
	{
	}

	Cell(int x, int y)
	{
		X = x;
		Y = y;
	}

	int X;		// ��
	int Y;		// �s
};

// �m�[�h
struct Node
{
	Node() :
		Node(0, 0)
	{
	}

	Node(int x, int y) :
		Position(x, y),
		HeuristicCost(Infinity),
		TotalCost(0)
	{
		AdjacentNodes.clear();
	}

	Cell Position;						// �m�[�h���W
	std::vector<Node*> AdjacentNodes;	// �אڃm�[�h(��)
	float HeuristicCost;				// �q���[���X�e�B�b�N�R�X�g
	float TotalCost;					// �R�X�g(�q���[���X�e�B�b�N�R�X�g����)
};

// �R�X�g�e�[�u��
int CostTable[MAP_HEIGHT][MAP_WIDTH] =
{
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
		{1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,},
		{1,0,1,1,0,1,1,1,1,0,1,0,1,1,1,1,0,1,1,0,1,},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
		{1,0,1,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,1,0,1,},
		{1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,},
		{1,1,1,1,0,1,1,1,1,0,1,0,1,1,1,1,0,1,1,1,1,},
		{0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,},
		{0,0,0,1,0,1,0,1,1,1,0,1,1,1,0,1,0,1,0,0,0,},
		{1,1,1,1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,1,1,1,},
		{0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,},
		{1,1,1,1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,1,1,1,},
		{0,0,0,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,0,0,0,},
		{0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,},
		{1,1,1,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,1,1,1,},
		{1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,},
		{1,0,1,1,0,1,1,1,1,0,1,0,1,1,1,1,0,1,1,0,1,},
		{1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,},
		{1,1,0,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,0,1,1,},
		{1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,},
		{1,0,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,0,1,},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
};

//// �o�H����
//int Map[MapHeight][MapWidth] =
//{
//	//0  1  2  3  4 
//	{ 0, 0, 0, 0, 0, }, // 0
//	{ 0, 0, 0, 0, 0, }, // 1
//	{ 0, 0, 1, 1, 1, }, // 2
//	{ 0, 0, 1, 1, 1, }, // 3
//	{ 0, 0, 1, 1, 1, }, // 4
//};
//

// �O���t
Node Map[MAP_HEIGHT][MAP_WIDTH];

// �����\�[�g�p�֐�
bool Less(Node* a, Node* b)
{
	if (a->TotalCost < b->TotalCost)
	{
		return true;
	}

	return false;
}

// �Z���͈̓`�F�b�N�֐�
bool IsCellWithinTheRange(int x, int y)
{
	if (x >= 0 &&
		x < MAP_WIDTH &&
		y >= 0 &&
		y < MAP_HEIGHT)
	{
		return true;
	}

	return false;
}

// �m�[�h�̍쐬
void CreateMap()
{
	for (int y = 0; y < MAP_HEIGHT; y++)
	{
		for (int x = 0; x < MAP_WIDTH; x++)
		{
			Map[y][x].Position.X = x;
			Map[y][x].Position.Y = y;

			Cell adjacent_cells[] =
			{
				Cell(x, y - 1),
				Cell(x - 1, y),
				Cell(x + 1, y),
				Cell(x, y + 1),
			};

			// �אڃm�[�h�̒ǉ�
			for (const Cell& cell : adjacent_cells)
			{
				if (IsCellWithinTheRange(cell.X, cell.Y) == true &&
					CostTable[cell.Y][cell.X] == 1)
				{
					Map[y][x].AdjacentNodes.push_back(&Map[cell.Y][cell.X]);
				}
			}
		}
	}
}

// �R�X�g������
void InitCost(int heuristic_cost, int total_cost)
{
	for (int y = 0; y < MAP_HEIGHT; y++)
	{
		for (int x = 0; x < MAP_WIDTH; x++)
		{
			Map[y][x].HeuristicCost = heuristic_cost;
			Map[y][x].TotalCost = total_cost;
		}
	}
}

// �q���[���X�e�B�b�N�R�X�g�v�Z(�m�[�h�ƃS�[���܂ł̋�����Ԃ��Ă���)
float CalculateHeuristic(const Node* node, const Node* Goal)
{
	float x = fabsf(Goal->Position.X - node->Position.X);
	float y = fabsf(Goal->Position.Y - node->Position.Y);

	return sqrtf(x * x + y * y);
}

// �Z����r
bool IsEqualCell(const Cell& a, const Cell& b)
{
	if (a.X == b.X &&
		a.Y == b.Y)
	{
		return true;
	}

	return false;
}

EraseResult EraseNode(std::list<Node*>& list, Node* new_node, float new_cost)
{
	// �N���[�Y���X�g�`�F�b�N
	for (auto itr = list.begin(); itr != list.end(); itr++)
	{
		// �m�[�h�Ɠ����Z�������邩���ׂ�
		if (IsEqualCell(new_node->Position, (*itr)->Position) == true)
		{
			// �R�X�g�̔�r
			if (new_cost < (*itr)->TotalCost)
			{
				list.erase(itr);
				return EraseResult::Erased;
			}
			else
			{
				return EraseResult::CouldntErased;
			}
		}
	}

	return EraseResult::NotFound;
}

// �I�[�v�����X�g�ɒǉ�
bool AddAdjacentNode(std::list<Node*>& open_list, std::list<Node*>& close_list, Node* adjacent_node, float cost)
{
	bool can_update = true;

	std::list<Node*> node_list[] =
	{
		close_list,
		open_list
	};

	for (std::list<Node*>& list : node_list)
	{
		// ���X�g�ɓ����m�[�h�������ă��X�g�̕��̃R�X�g�������Ȃ�폜
		if (EraseNode(list, adjacent_node, cost) == EraseResult::CouldntErased)
		{
			can_update = false;
		}
	}

	if (can_update == true)
	{
		open_list.push_back(adjacent_node);
		return true;
	}

	return false;
}

void AStar(Cell start, Cell goal)
{
	std::list<Node*> open_list;
	std::list<Node*> close_list;

	//const Node* start_node = &Map[start.Y][start.X];
	const Node* goal_node = &Map[goal.Y][goal.X];

	// �X�V�����m�[�h�ʒu�ۑ��p
	Cell last_update_cells[MAP_HEIGHT][MAP_WIDTH];

	// �O���t�̏�����
	InitCost(Infinity, 0);

	// �X�^�[�g�m�[�h�̎w��
	open_list.push_back(&Map[start.Y][start.X]);

	// �o�H�T����
	int count = 0;

	// �I�[�v�����X�g���Ȃ��Ȃ�܂ŉ�
	while (open_list.empty() == false)
	{
		count++;

		Node* search_node = (*open_list.begin());
		// �T�����X�g���珜�O
		open_list.erase(open_list.begin());

		// �S�[���ɓ��B������I���
		if (IsEqualCell(search_node->Position, goal) == true)
		{
			// �N���[�Y���X�g�ɍŌ�̃m�[�h��ǉ�����
			close_list.push_back(search_node);
			break;
		}

		for (Node* adjacent_node : search_node->AdjacentNodes)
		{
			// �v�Z���s���Ă��Ȃ������ꍇ�����v�Z
			if (adjacent_node->HeuristicCost == Infinity)
			{
				// �q���[���X�e�B�N�X�R�X�g�v�Z
				adjacent_node->HeuristicCost = CalculateHeuristic(adjacent_node, goal_node);
			}

			// �m�[�h�ԃR�X�g
			float edge_cost = CostTable[adjacent_node->Position.Y][adjacent_node->Position.X];
			// �擾�m�[�h�̃g�[�^���R�X�g
			float node_cost = search_node->TotalCost;
			/*
				�g�[�^���R�X�g�Z�o
					�m�[�h�ԃR�X�g + �q���[���X�e�B�b�N�R�X�g + �擾�m�[�h�̃g�[�^���R�X�g
			*/
			float total_cost = edge_cost + adjacent_node->HeuristicCost + node_cost;

			// �m�[�h�ǉ�
			if (AddAdjacentNode(open_list, close_list, adjacent_node, total_cost) == true)
			{
				// �g�[�^���R�X�g���X�V
				adjacent_node->TotalCost = total_cost;

				if (adjacent_node->Position.Y == 0 && adjacent_node->Position.X == 2)
				{
					int xx = 0;
					xx = 100;
				}

				// �o�H���X�V�����Z����ۑ�
				last_update_cells[adjacent_node->Position.Y][adjacent_node->Position.X] = search_node->Position;
			}
		}

		bool is_add_close = true;

		// �N���[�Y���X�g�`�F�b�N
		for (auto itr = close_list.begin(); itr != close_list.end(); itr++)
		{
			// �m�[�h�Ɠ����Z�������邩���ׂ�
			if (IsEqualCell(search_node->Position, (*itr)->Position) == true)
			{
				is_add_close = false;
				break;
			}
		}

		// �����m�[�h�����������̂Œǉ�
		if (is_add_close == true)
		{
			// ���̃m�[�h�̒T���I��
			close_list.push_back(search_node);
		}

		// �����\�[�g
		open_list.sort(Less);
	}

	// �o�H����
	std::list<Cell> route_list;

	// �S�[���Z�����畜������
	route_list.push_back(goal);
	while (route_list.empty() == false)
	{
		Cell route = route_list.front();

		// �X�^�[�g�Z���Ȃ�I��
		if (IsEqualCell(route, start) == true)
		{
			// ���������o�H��\��
			for (Cell& cell : route_list)
			{
				printf("x = %d y = %d\n", cell.X, cell.Y);
			}
			break;
		}
		else
		{
			if (IsCellWithinTheRange(route.X, route.Y) == true)
			{
				// �ǉ�
				route_list.push_front(last_update_cells[route.Y][route.X]);
			}
			else
			{
				printf("�o�H�͌�����Ȃ�����\n");
				break;
			}
		}
	}

	printf("�T���� = %d\n", count);
}

int main()
{
	CreateMap();

	Cell start = Cell(3, 1);
	Cell goal = Cell(0, 0);

	AStar(start, goal);

	return 0;
}