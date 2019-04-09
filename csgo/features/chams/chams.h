#pragma once
#include "../../inc.hpp"

enum shader_type_t {
	VertexLitGeneric,
	UnlitGeneric,
	Modulate
};

class c_chams {
private:
	std::pair< i_material *, i_material * > m_shaded_mat;
	std::pair< i_material *, i_material * > m_flat_mat;
	std::pair< i_material *, i_material * > m_modulate_mat;

	bool m_applied = false;
	std::vector< std::pair< c_csplayer *, float > > m_players;

	void push_players( );
	i_material *create_material( shader_type_t shade, bool ignorez, bool wireframe = false );
	
	
public:
	void on_sceneend( );
	bool on_dme( IMatRenderContext *ctx, void *state, const model_render_info_t &pInfo, matrix3x4_t *pCustomBoneToWorld );
};

extern c_chams g_chams;