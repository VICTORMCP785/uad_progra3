#include "..\Include\CCamera.h"

CCamera::CCamera()
{

}

CCamera::CCamera(CVector3 Pos, int W, int H, float FoV, float Near, float Far, CVector3 LookAt)
{
	m_Pos = Pos;
	m_W = W;
	m_H = H;
	m_Fov = FoV;
	m_Near = Near;
	m_Far = Far;
	m_LookAt = LookAt;

	float Aspect = float(m_W) / float(m_H);

	ProyectionMatrix = MathHelper::PerspectiveProjectionMatrix(FoV, Aspect, Near, Far);
	Recalc();
}

CCamera::~CCamera()
{

}

bool CCamera::IsVisible(CAABB_2D Limit)
{
	return (m_Frustum.isAABBVisible2D(Limit) == CFrustum::FRUSTUM_VISIBILITY_TEST_RESULT::INTERSECT || 
		m_Frustum.isAABBVisible2D(Limit) == CFrustum::FRUSTUM_VISIBILITY_TEST_RESULT::INSIDE);
}

void CCamera::Recalc()
{
	CVector3 Forward;
	CVector3 LocalUp = CVector3(0.0f, 1.0f, 0.0f);

	Forward = m_LookAt - m_Pos;
	Forward.normalize();

	m_Right = LocalUp.cross(Forward);
	m_Right.normalize();
	m_Right *= -1.0f;

	m_Up = Forward.cross(m_Right);
	m_Up.normalize();

	ViewMatrix = MathHelper::ViewMatrix(m_Pos, m_LookAt, m_Up);
	float Aspect = float(m_W) / float(m_H);
	m_Frustum.update(m_Pos, m_LookAt, m_Up, m_Right, m_Near, m_Far, m_Fov, Aspect);
}

void CCamera::MoveCam(float Xmove, float Zmove)
{
	CVector3 Forward;
	CVector3 Right;

	Forward = m_LookAt - m_Pos;
	Forward.normalize();

	Right = m_Up.cross(Forward);
	Right.normalize();

	Right.X += Xmove;
	Right.Z += Zmove;

	m_Pos += Right;
	m_LookAt += Right;

	Recalc();
}

MathHelper::Matrix4 CCamera::GetProyectionMatrix()
{
	return ProyectionMatrix;
}

MathHelper::Matrix4 CCamera::GetViewMatrix()
{
	return ViewMatrix;
}
