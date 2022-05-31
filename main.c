
#include <stdio.h>
#include <stdlib.h>

typedef struct item
{
	int	value;
	int	move;
}	t_item;

typedef struct map
{
	t_item	*items;
	int		index;
}	t_map;

static int	init(t_map **map, int map_size, int item_size)
{
	int		i;
	int		j;
	int		gap;

	*map = malloc(sizeof(t_map) * map_size);
	if (!*map)
		return (0);
	i = 0;
	gap = 0;
	while (i < map_size)
	{
		map[0][i].index = -1;
		map[0][i].items = malloc(sizeof(t_item) * item_size);
		if (!map[0][i].items)
			return (0);
		j = 0;
		while (j < item_size)
		{
			map[0][i].items[j].value = j + gap;
			map[0][i].items[j].move = -1;
			j++;
		}
		gap += item_size;
		i++;
	}
	return (1);
}

int	main(void)
{
	int		*values;
	t_map	*map;

	if (!init(&map, 3, 3))
		return (0);
	values = &map[0].items[0].value;
	printf("[%p] %d\n", values, values[0]);
	values += sizeof(t_map) / 2;
	printf("[%p] %d\n", values, values[0]);
	values += sizeof(t_map) / 2;
	printf("[%p] %d\n", values, values[0]);
	values += sizeof(t_map) / 2;
	printf("[%p] %d\n", values, values[0]);
	return (0);
}
