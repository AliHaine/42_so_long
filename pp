	/*
	while (1 + 1 == 2)
	{
		if (prev != NULL)
			printf("before prec = %p\n", (prev)->prev);
		while (line[i] && line[i] != '\n')
		{
			if (i > 0)
				printf("start prec = %p\n", (prev)->prev);
			prev = setup_map_struct(line[i], x, y, &prev);
			if (!prev)
				return (0);
			x++;
			i++;
		}
		i = 0;
		y++;
		x = 0;
		printf("precEnd = %p\n", (prev));
		test_parcour(prev);
		break;

		printf("next = %p\n", prev->next);
		printf("precEnd = %p\n", (prev)->prev);
		printf("precEnd = %p\n", (prev)->prev);
	}*/