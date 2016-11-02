llist select_list;
scroll_bar scroll1 = { 18,200,398, 44,18,0,115,15,0,0xeeeeee,0xD2CED0,0x555555,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1};
dword select_list_count_offset;

?define T_SELECT_LIST_NO_DATA "No data to show"

void InitSelectList(dword _x, _y, _w, _h, _no_selection)
{
	select_list.no_selection = _no_selection;
	select_list.SetFont(8, 14, 0x90);
	select_list.SetSizes(_x, _y, _w, _h, 20);
}

void DrawSelectList(dword _items_count)
{
	int i, list_last;

	select_list.count = _items_count;
	select_list.CheckDoesValuesOkey();

	if (select_list.count > select_list.visible) list_last = select_list.visible; else list_last = select_list.count;

	for (i=0; i<select_list.visible; i++;) DeleteButton(select_list.first + i + 100);
	for (i=0; i<select_list.visible; i++;) DeleteButton(select_list.first + i + 300);

	for (i=0; i<list_last; i++;)
	{
		DrawBar(select_list.x,i*select_list.item_h+select_list.y,select_list.w, select_list.item_h, 0xFFFfff);
		DrawSelectList_Line(i); //NEED TO BE IMPLEMENTED IN APP
	}
	DrawBar(select_list.x,i*select_list.item_h+select_list.y, select_list.w, -i*select_list.item_h+ select_list.h, 0xFFFfff);
	if (!select_list.count) WriteText(-strlen(T_SELECT_LIST_NO_DATA)*select_list.font_w + select_list.w / 2 + select_list.x + 1, 
		select_list.h / 2 - 8 + select_list.y, select_list.font_type, 0x999999, T_SELECT_LIST_NO_DATA);
	DrawSelectListScroller();
}


void DrawSelectListScroller()
{
	scroll1.bckg_col = MixColors(system.color.work, 0xBBBbbb, 80);
	scroll1.frnt_col = MixColors(system.color.work,0xFFFfff,120);
	scroll1.line_col = system.color.work_graph;

	scroll1.max_area = select_list.count;
	scroll1.cur_area = select_list.visible;
	scroll1.position = select_list.first;

	scroll1.all_redraw=1;
	scroll1.start_x = select_list.x + select_list.w;
	scroll1.start_y = select_list.y-1;
	scroll1.size_y = select_list.h+2;

	scrollbar_v_draw(#scroll1);
}