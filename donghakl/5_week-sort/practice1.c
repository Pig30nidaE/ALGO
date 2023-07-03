#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct draw
{
	int width;
	int height;
	char symbol;
	char **map;
} draw;

typedef struct exe
{
	char	type;
	float	x;
	float	y;
	float	width;
	float	height;
	char	symbol;
}	exe;


int apply_op(draw *draw, exe *exe)
{
	int i;
	int j;
	if ((exe->width <= 0.00000000) || (exe->height <= 0.00000000) || (exe->type != 'R' && exe->type != 'r'))
		return (1);
	i = -1;
	while (++i < draw->width)
	{
		j = -1;
		while (++j < draw->height)
			execute_one(exe, draw, i, j);
	}
	return (0);
}

int get_info(FILE *file, draw *draw)
{
	int cnt;
	int i;
	int j;
	char **tmp;

	cnt = fscanf(file, "%d %d %c", &draw->width, &draw->height, &draw->symbol);
	if (cnt == 3)
	{
		if (draw->width > 0 && draw->width < 301 && draw->height > 0 && draw->height < 301)
		{
			tmp = (char **)malloc(sizeof(char *) * draw->height + 1);
			tmp[draw->height] = NULL;
			i = -1;
			while (++i < draw->height)
			{
				tmp[i] = (char *)malloc(sizeof(char) * draw->width);
			}
			i = -1;
			while (++i < draw->height)
			{
				j = -1;
				while (++j < draw->width)
				{
					tmp[i][j] = draw->symbol;
				}
			}
			draw->map = tmp;
			return (0);
		}

	}
	return (1);
}

int execute(FILE *file)
{
	draw draw;
	exe exe;
	int cnt;
	if (!get_info(file, &draw))
	{
		cnt = fscanf(file, "%c %f %f %f %f %c", &exe.type, &exe.x, &exe.y, &exe.width, &exe.height, &exe.symbol);
		while (cnt == 6)
		{
			if (apply_op(&drawing, &exe))
				return (1);
			cnt = fscanf(file, "%c %f %f %f %f %c", &exe.type, &exe.x, &exe.y, &exe.width, &exe.height, &exe.symbol);
		}
		if (cnt == -1)
		{
			print_map(&draw);
			return (0);
		}

		//test;
		for (int i = 0; i < draw.height; i++)
		{
			for (int j = 0; j < draw.width; j++)
			{
				printf("%c", draw.map[i][j]);
			}
			printf("\n");
		}
		// test;
		return (0);
	}
	return (1);
}

int main(int argc, char **argv)
{
	FILE *file;
	int i;

	if (argc == 2)
	{
		file = fopen(argv[1], "r");
		if (file && !execute(file))
			return (0);
		write(1, "error1\n", 6);
	}
	else
	{
		write(1, "error2\n", 6);
	}
	return (1);
}