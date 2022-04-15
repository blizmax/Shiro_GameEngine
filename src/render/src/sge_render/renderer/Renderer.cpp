#include "Renderer.h"

namespace sge {

Renderer* Renderer::_current = nullptr;

Renderer::CreateDesc::CreateDesc() {
#if SGE_OS_WINDOWS
	apiType = ApiType::DX11;
#else
	apiType = ApiType::None;
#endif

	multithread = false;
}

Renderer* Renderer::create(CreateDesc& desc) {
	Renderer* p = nullptr;

	/*
	switch (desc.apiType) {
		case ApiType::DX11: p = new Renderer_DX11(desc); break;
		default: throw SGE_ERROR("unsupport graphic api");
	}*/

	return p;
}

Renderer::Renderer() {
	SGE_ASSERT(_current == nullptr);
	_currentRenderSystem = new RenderSystem_D3D11(); //hardcode
	SGE_ASSERT(_currentRenderSystem == nullptr);
	_current = this;
}

Renderer::~Renderer() {
	SGE_ASSERT(_current == this);

	_currentRenderSystem = nullptr;
	_current = nullptr;
}

}