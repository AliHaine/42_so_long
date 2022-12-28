/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagmur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:04:01 by ayagmur           #+#    #+#             */
/*   Updated: 2022/12/28 17:04:03 by ayagmur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	print_enum_msg(enum MSG id)
{
	if (id == ERROR)
		return (ft_putstr("Une erreur est survenue"));
	else if (id == ERROR_ARGS_NUMBER)
		return (ft_putstr("Le nombre d'argument n'est pas valide"));
	else if (id == ERROR_MAP)
		return (ft_putstr("Une erreur est survenue avec la carte"));
	else if (id == ERROR_PLAYER_TOHIGH)
		return (ft_putstr("Erreur, il y plus d'un joueur dans la map"));
	else if (id == ERROR_NO_PLAYER)
		return (ft_putstr("Erreur, il n'y a aucun joueur dans la map"));
	else if (id == ERROR_EXIT_TOHIGH)
		return (ft_putstr("Erreur, il y plus d'une sortie dans la map"));
	else if (id == ERROR_NO_EXIT)
		return (ft_putstr("Erreur, il n'y a aucune sortie dans la map"));
	else if (id == ERROR_NO_WALL)
		return (ft_putstr("Erreur, la map n'est pas correctement fermé"));
	else
		return (ft_putstr("Le message spécifié n'est pas répertorié"));
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (0);
}
