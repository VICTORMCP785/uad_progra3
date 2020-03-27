#pragma once
#include "MathHelper.h"
#include "CFrustum.h"
class CCamera
{
public:
	CCamera();
	CCamera(CVector3 Pos, int W, int H, float FoV,float Near,float Far, CVector3 LookAt);
	~CCamera();
	bool IsVisible(CAABB_2D Limit);
	void Recalc();
	void MoveCam(float Xmove,float Zmove);
	MathHelper::Matrix4 GetProyectionMatrix();
	MathHelper::Matrix4 GetViewMatrix();

private:
	CVector3 m_Pos;
	CVector3 m_LookAt;
	CVector3 m_Up;
	CVector3 m_Right;

	int m_W;
	int m_H;
	float m_Fov;
	float m_Near;
	float m_Far;

	MathHelper::Matrix4 ViewMatrix;
	MathHelper::Matrix4 ProyectionMatrix;

	CFrustum m_Frustum;
};
