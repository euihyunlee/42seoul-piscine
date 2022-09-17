/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:29:42 by euihlee           #+#    #+#             */
/*   Updated: 2022/09/12 22:30:26 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

// t_node는 연결 리스트의 노드 하나하나를 나타냅니다.
// 각 노드는 'rush02.h'에 정의되어 있듯이 key(':' 앞에 오는 숫자), value(':' 뒤에 오는 문자열)
// 문자열과 다음 노드를 가리키는 포인터(t_node *)를 하나로 묶어 놓은 구조체입니다.
// 연결 리스트 자체는 첫 번째 노드를 가리키는 포인터, 즉 t_node *라고 보시면 됩니다.
// 그럼 t_node **는 연결 리스트 자체를 가리키는 이중 포인터로 보는 게 편할듯 합니다.

// load: 파일명과 연결 리스트를 가리키는 이중 포인터를 받아서 연결 리스트를 직접 만든 뒤
// 성공하면 SUCCESS를, 실패하면 ERROR를 반환.
// 참고: SUCCESS와 ERROR는 'rush02.h'에서 각각 1과 0으로 #define 되어 있음.
int	load(char *dict, t_node **list)
{
	// 저희가 쓸 open은 파일을 성공적으로 열었을 때 file descriptor(줄여서 fd)를 반환합니다.
	// 이 fd는 3보다 큰 int값인데, 3보다 큰 이유는 0, 1, 2가 각각 stdin, stdout, stderr로
	// 이미 지정되어 있기 때문입니다. 만약 파일을 여는 데 실패했다면? -1을 반환합니다.
	int	fd1;
	int	fd2;

	// dict라는 파일을 read only 모드로 열어 줍니다. 
	fd1 = open(dict, O_RDONLY);
	fd2 = open(dict, O_RDONLY);
	// 똑같은 파일을 두 번 여는 이유는 다음과 같습니다: 저희가 쓰는 read 시스템 콜은 마치 점자를
	// 손가락으로 읽는 것처럼 처음부터 끝까지 문자를 하나하나 읽어 나갑니다. 단, 손가락을 마음대로
	// 움직일 수 있는 우리와는 다르게 read는 오로지 한 방향으로만 파일을 읽을 수 있습니다.
	// 즉, 문자를 직접 읽어 보기 전에는 앞에 어떤 문자가 올지 알 수도 없고, 읽고자 하는 범위를
	// 넘어섰을 때 손가락을 되돌릴 방법도 없습니다. 그럼 손가락을 두 개 쓰면 어떨까요? 오른손은 문자를
	// 하나하나 읽어 가며 파일이 어떤 모습인지를 파악하고, 왼손은 오른손을 따라 가며 필요한 부분만, 그리고
	// 필요한 길이 만큼만 연결 리스트에 저장하는 것입니다.

	// dict 파일을 가리키는 손가락 두 개와 연결 리스트를 가리키는 포인터를 들고 parse_dict로 갑니다.
	// parse_dict는 dict.c에 있습니다.

	// parse_dict가 실패했을 경우...
	if (!parse_dict(fd1, fd2, list))
	{

		write(1, "Dict Error\n", 11);
		// 파일을 닫고...
		close(fd1);
		close(fd2);
		// 파일을 닫고 연결 리스트를 free해 줍니다.
		unload(list);
		// 그리고 ERROR를 반환합니다.
		return (ERROR);
	}
	// parse_dict가 성공했을 경우 파일을 닫고 SUCCESS를 반환합니다.
	close(fd1);
	close(fd2);
	return (SUCCESS);
}

// load_entry: key 문자열, value 문자열, 그리고 연결 리스트를 가리키는 포인터를 받아서
// 연결 리스트를 구현하는 함수. 
int	load_entry(char *key, char *val, t_node **list)
{
	t_node			*entry;

	// entry는 연결 리스트의 노드를 가리키는 포인터입니다. 물론 연결 리스트는 아직 존재하지 않습니다.
	entry = malloc(sizeof (t_node));
	if (entry == NULL)
		return (ERROR);
	// entry->key는 (*entry).key와 같은 뜻입니다. 즉, 포인터를 역참조해 t_node 구조체를 접근하고
	// 구조체의 key값을 key 문자열로, val 값을 val 문자열로, 그리고 next값을 NULL 포인터로 초기화해 주는
	// 것입니다.  
	entry->key = key;
	entry->val = val;
	entry->next = NULL;
	// list 는 연결 리스트를 가리키는 포인터라고 말해 드렸습니다. 그럼 *list는 연결 리스트를 의미합니다.
	// 앞서 말했다시피, 연결 리스트는 첫 번째 노드를 가리키는 포인터에 불과합니다.
	// list ----> *list ----> | node1 |
	//                        | key   |
	//                        | val   |
	//                        | next  |---> | node2 |
	//                                      | key   |
	//                                      | val   |
	//                                      | next  |----> ... ----> NULL
	// 즉, *list가 NULL이란 말은 곧 리스트가 아직 존재하지 않는다는 말입니다.
	// *list가 NULL이 아니라면 적어도 위 그림의 node1이 존재한다는 말입니다.   
	// 그런 경우에는 그림이 다음과 같이 바뀝니다.
	if (*list != NULL)
		entry->next = *list;
	*list = entry;
	// list ----> *list           > | node1 |
	//            |             /   | key   |
	//            V            /    | val   |
	//            | entry |   /     | next  |---> | node2 |
	//            | key   |  /                    | key   |
	//            | val   | /                     | val   |
	//            | next  |/                      | next  |----> ... ----> NULL
	// parse_dict가 읽는 줄마다 이 작업을 반복해 줌으로써 연결 리스트를 앞에서부터 만들어 나갑니다.
	// 이제 다시 parse_dict 함수로 돌아가셔도 좋습니다.
	return (SUCCESS);
}

// unload: 연결 리스트를 끝까지 따라가며 노드를 하나씩 free해 줍니다.
void	unload(t_node **list)
{
	t_node	*tmp;

	while (*list != NULL)
	{
		tmp = (*list)->next;
		free((*list)->key);
		free((*list)->val);
		free(*list);
		*list = tmp;
	}
	return ;
}