/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awadeng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:50:44 by awadeng           #+#    #+#             */
/*   Updated: 2024/02/08 22:31:56 by awadeng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map *data)
{
	if (!data)
		return ;
	ft_free_strs(data->strs);
	free(data);
}

void	free_map_status(t_map_status *data)
{
	if (!data)
		return ;
	if (data->map != NULL)
		free_map(data->map);
	free(data);
}

void	free_assets(t_mlx *mlx)
{
	if (!mlx || !mlx->assets)
		return ;
	if (mlx->assets->img_bg != NULL)
		mlx_destroy_image(mlx->mlx, mlx->assets->img_bg);
	if (mlx->assets->img_w != NULL)
		mlx_destroy_image(mlx->mlx, mlx->assets->img_w);
	if (mlx->assets->img_p != NULL)
		mlx_destroy_image(mlx->mlx, mlx->assets->img_p);
	if (mlx->assets->img_c != NULL)
		mlx_destroy_image(mlx->mlx, mlx->assets->img_c);
	if (mlx->assets->img_exit != NULL)
		mlx_destroy_image(mlx->mlx, mlx->assets->img_exit);
	free(mlx->assets);
	mlx->assets = NULL;
}

void	free_mlx(t_mlx *data)
{
	if (!data)
		return ;
	if (data->map != NULL)
		free_map_status(data->map);
	if (data->assets != NULL)
		free_assets(data);
	if (data->mlx_img != NULL)
		mlx_destroy_image(data->mlx, data->mlx_img);
	if (data->mlx_win != NULL)
		mlx_destroy_window(data->mlx, data->mlx_win);
	if (data->mlx != NULL)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		data->mlx = NULL;
	}
	free(data);
}

void	print_error(void *data, int mode, char *message)
{
	if (mode == 0)
		free_mlx(data);
	else if (mode == 1)
		free_assets(data);
	else if (mode == 2)
		free_map_status(data);
	else if (mode == 3)
		free_map(data);
	else if (mode == 4)
		ft_free_strs(data);
	ft_putstr_fd(message, 2);
	exit(1);
}
