/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joowpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 12:53:26 by joowpark          #+#    #+#             */
/*   Updated: 2023/01/13 15:50:28 by joowpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_tokens(char **tokens)
{
	char	**line;

	line = tokens;
	while (*line)
	{
		free(*line);
		line += 1;
	}
	free(tokens);
}

void	free_tree(struct s_node *node)
{
	struct s_node	*left;
	struct s_node	*right;

	left = node->left;
	right = node->right;
	if (node->here_doc)
		free(node->here_doc);
	if (node->line)
		free(node->line);
	if (node)
		free(node);
	if (left)
		free_tree(left);
	if (right)
		free_tree(right);
}

void	free_node_line(char **node_line)
{
	free(*node_line);
	*node_line = NULL;
}

void	free_trees(struct s_node **trees)
{
	struct s_node	**tmp;

	tmp = trees;
	while (*tmp)
	{
		free_tree(*tmp);
		tmp ++;
	}
	free(trees);
}
