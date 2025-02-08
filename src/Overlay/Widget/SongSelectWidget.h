#pragma once
#include "SongSelectWidget.h"

#include "Core/interfaces.h"
#include "Game/gamestates.h"
#include "Game/stages.h"
#include "Overlay/imgui_utils.h"

// TODO: Count the songs.
void SongSelectWidget()
{
	if (g_gameVals.musicSelect_X != nullptr &&
		g_gameVals.musicSelect_Y != nullptr)
	{
		static unsigned char selectedSong = 0;

		for (int i = 0; i < STAGES_COUNT; i++)
		{
			if (stages[i][0] == *g_gameVals.musicSelect_X &&
				stages[i][1] == *g_gameVals.musicSelect_Y)
			{
				selectedSong = i;
				break;
			}
		}

		ImGui::AlignTextToFramePadding();
		ImGui::TextUnformatted("Song"); ImGui::SameLine();
		if (ImGui::SliderByte("##Song", &selectedSong, 0, STAGES_COUNT))
		{
			*g_gameVals.musicSelect_X = stages[selectedSong][0];
			*g_gameVals.musicSelect_Y = stages[selectedSong][1];
		}
	}
}

