xof 0303txt 0032
template Frame {
 <3d82ab46-62da-11cf-ab39-0020af71e433>
 [...]
}

template Matrix4x4 {
 <f6f23f45-7686-11cf-8f52-0040333594a3>
 array FLOAT matrix[16];
}

template FrameTransformMatrix {
 <f6f23f41-7686-11cf-8f52-0040333594a3>
 Matrix4x4 frameMatrix;
}

template Vector {
 <3d82ab5e-62da-11cf-ab39-0020af71e433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template MeshFace {
 <3d82ab5f-62da-11cf-ab39-0020af71e433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template Mesh {
 <3d82ab44-62da-11cf-ab39-0020af71e433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

template MeshNormals {
 <f6f23f43-7686-11cf-8f52-0040333594a3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template ColorRGBA {
 <35ff44e0-6c7c-11cf-8f52-0040333594a3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <d3e16e81-7835-11cf-8f52-0040333594a3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template Material {
 <3d82ab4d-62da-11cf-ab39-0020af71e433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshMaterialList {
 <f6f23f42-7686-11cf-8f52-0040333594a3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material <3d82ab4d-62da-11cf-ab39-0020af71e433>]
}

template AnimTicksPerSecond {
 <9e415a43-7ba6-4a73-8743-b73d47e88476>
 DWORD AnimTicksPerSecond;
}

template Animation {
 <3d82ab4f-62da-11cf-ab39-0020af71e433>
 [...]
}

template AnimationSet {
 <3d82ab50-62da-11cf-ab39-0020af71e433>
 [Animation <3d82ab4f-62da-11cf-ab39-0020af71e433>]
}

template FloatKeys {
 <10dd46a9-775b-11cf-8f52-0040333594a3>
 DWORD nValues;
 array FLOAT values[nValues];
}

template TimedFloatKeys {
 <f406b180-7b3b-11cf-8f52-0040333594a3>
 DWORD time;
 FloatKeys tfkeys;
}

template AnimationKey {
 <10dd46a8-775b-11cf-8f52-0040333594a3>
 DWORD keyType;
 DWORD nKeys;
 array TimedFloatKeys keys[nKeys];
}


Frame Grass_Short {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000;;
 }

 Mesh Grass_Short {
  408;
  -0.099628;-0.005342;0.214821;,
  -0.134580;0.224407;0.237296;,
  -0.122479;0.224407;0.208855;,
  -0.114435;-0.005342;0.249623;,
  -0.134580;0.224407;0.237296;,
  -0.107032;0.335756;0.232222;,
  -0.122479;0.224407;0.208855;,
  0.074600;-0.005342;0.021135;,
  0.065000;0.161579;0.061565;,
  0.053998;0.161579;0.032681;,
  0.088063;-0.005342;0.056479;,
  0.065000;0.161579;0.061565;,
  0.081332;0.232197;0.038807;,
  0.053998;0.161579;0.032681;,
  -0.150768;-0.005342;0.112628;,
  -0.116744;0.224407;0.136483;,
  -0.147649;0.224407;0.136038;,
  -0.112951;-0.005342;0.113173;,
  -0.116744;0.224407;0.136483;,
  -0.131860;0.335756;0.112900;,
  -0.147649;0.224407;0.136038;,
  0.040985;-0.005342;-0.157222;,
  0.082511;0.287886;-0.155705;,
  0.056333;0.287886;-0.139273;,
  0.073018;-0.005342;-0.177330;,
  0.082511;0.287886;-0.155705;,
  0.057002;0.399234;-0.167276;,
  0.056333;0.287886;-0.139273;,
  0.090341;-0.005342;0.171229;,
  0.113398;0.161579;0.136659;,
  0.113672;0.161579;0.167566;,
  0.090006;-0.005342;0.133409;,
  0.113398;0.161579;0.136659;,
  0.090174;0.232197;0.152319;,
  0.113672;0.161579;0.167566;,
  -0.001153;-0.005342;0.103596;,
  -0.017949;0.224407;0.065588;,
  0.008277;0.224407;0.081944;,
  -0.033244;-0.005342;0.083582;,
  -0.017949;0.224407;0.065588;,
  -0.017199;0.335756;0.093590;,
  0.008277;0.224407;0.081944;,
  -0.161604;-0.005342;0.041125;,
  -0.150625;0.161579;0.001048;,
  -0.140619;0.161579;0.030292;,
  -0.173848;-0.005342;0.005341;,
  -0.150625;0.161579;0.001048;,
  -0.167726;0.232197;0.023233;,
  -0.140619;0.161579;0.030292;,
  -0.083222;-0.005342;-0.013096;,
  -0.041698;0.118158;-0.011509;,
  -0.067904;0.117458;0.004879;,
  -0.051155;-0.005342;-0.033150;,
  -0.041698;0.118158;-0.011509;,
  -0.067188;0.228806;-0.023123;,
  -0.067904;0.117458;0.004879;,
  0.083846;-0.005342;-0.067294;,
  0.125207;0.270594;-0.071288;,
  0.101436;0.270594;-0.051534;,
  0.112934;-0.005342;-0.091466;,
  0.125207;0.270594;-0.071288;,
  0.098390;0.381942;-0.079380;,
  0.101436;0.270594;-0.051534;,
  -0.015225;-0.005342;0.172697;,
  0.026136;0.055330;0.168702;,
  0.002364;0.055330;0.188456;,
  0.013863;-0.005342;0.148525;,
  0.026136;0.055330;0.168702;,
  -0.000681;0.125948;0.160611;,
  0.002364;0.055330;0.188456;,
  -0.114910;-0.005342;-0.060139;,
  -0.123121;0.118158;-0.100874;,
  -0.101035;0.118158;-0.079251;,
  -0.141935;-0.005342;-0.086598;,
  -0.123121;0.118158;-0.100874;,
  -0.128422;0.229507;-0.073369;,
  -0.101035;0.118158;-0.079251;,
  -0.048394;-0.005342;-0.097056;,
  -0.030577;0.118158;-0.134596;,
  -0.025838;0.118158;-0.104053;,
  -0.054193;-0.005342;-0.134429;,
  -0.030577;0.118158;-0.134596;,
  -0.051294;0.229507;-0.115742;,
  -0.025838;0.118158;-0.104053;,
  -0.082444;-0.005125;0.222132;,
  -0.117386;0.224338;0.244611;,
  -0.097251;-0.005125;0.256934;,
  -0.105285;0.224338;0.216170;,
  -0.117386;0.224338;0.244611;,
  -0.105285;0.224338;0.216170;,
  -0.089880;0.335308;0.239519;,
  0.091744;-0.004931;0.028118;,
  0.082179;0.161490;0.068562;,
  0.105206;-0.004931;0.063461;,
  0.071164;0.161324;0.039672;,
  0.082179;0.161490;0.068562;,
  0.071164;0.161324;0.039672;,
  0.098311;0.231233;0.045723;,
  -0.166853;-0.004795;0.105023;,
  -0.132871;0.224103;0.128859;,
  -0.129036;-0.004795;0.105568;,
  -0.163790;0.224242;0.128406;,
  -0.132871;0.224103;0.128859;,
  -0.163790;0.224242;0.128406;,
  -0.147752;0.334640;0.105387;,
  0.023954;-0.005078;-0.164695;,
  0.065468;0.287767;-0.163183;,
  0.055987;-0.005078;-0.184802;,
  0.039288;0.287817;-0.146752;,
  0.065468;0.287767;-0.163183;,
  0.039288;0.287817;-0.146752;,
  0.040018;0.398691;-0.174728;,
  0.073145;-0.005017;0.164054;,
  0.096180;0.161506;0.129475;,
  0.072810;-0.005017;0.126235;,
  0.096458;0.161425;0.160383;,
  0.096180;0.161506;0.129475;,
  0.096458;0.161425;0.160383;,
  0.073081;0.231432;0.145187;,
  -0.014894;-0.004266;0.099348;,
  -0.031869;0.224028;0.061284;,
  -0.046986;-0.004266;0.079334;,
  -0.005607;0.223816;0.077652;,
  -0.031869;0.224028;0.061284;,
  -0.005607;0.223816;0.077652;,
  -0.030334;0.333632;0.089528;,
  -0.178759;-0.004943;0.034117;,
  -0.167812;0.161493;-0.005973;,
  -0.191003;-0.004943;-0.001667;,
  -0.157795;0.161336;0.023275;,
  -0.167812;0.161493;-0.005973;,
  -0.157795;0.161336;0.023275;,
  -0.184726;0.231262;0.016288;,
  -0.100252;-0.005078;-0.020569;,
  -0.058741;0.118039;-0.018988;,
  -0.068186;-0.005078;-0.040623;,
  -0.084948;0.117389;-0.002600;,
  -0.058741;0.118039;-0.018988;,
  -0.084948;0.117389;-0.002600;,
  -0.084171;0.228263;-0.030575;,
  0.066761;-0.005098;-0.074731;,
  0.108112;0.270492;-0.078730;,
  0.095849;-0.005098;-0.098902;,
  0.084339;0.270530;-0.058976;,
  0.108112;0.270492;-0.078730;,
  0.084339;0.270530;-0.058976;,
  0.081346;0.381440;-0.086799;,
  -0.032299;-0.005007;0.165265;,
  0.009045;0.055162;0.161263;,
  -0.003210;-0.005007;0.141093;,
  -0.014732;0.055256;0.181014;,
  0.009045;0.055162;0.161263;,
  -0.014732;0.055256;0.181014;,
  -0.017646;0.125160;0.153227;,
  -0.131484;-0.004776;-0.066399;,
  -0.139755;0.117986;-0.107156;,
  -0.158509;-0.004776;-0.092858;,
  -0.117655;0.117843;-0.085528;,
  -0.139755;0.117986;-0.107156;,
  -0.117655;0.117843;-0.085528;,
  -0.144784;0.228353;-0.079548;,
  -0.065594;-0.005087;-0.104171;,
  -0.047790;0.118092;-0.141717;,
  -0.071393;-0.005087;-0.141545;,
  -0.043050;0.118047;-0.111174;,
  -0.047790;0.118092;-0.141717;,
  -0.043050;0.118047;-0.111174;,
  -0.068449;0.228982;-0.122839;,
  -0.117386;0.224338;0.244611;,
  -0.114435;-0.005342;0.249623;,
  -0.097251;-0.005125;0.256934;,
  -0.134580;0.224407;0.237296;,
  -0.097251;-0.005125;0.256934;,
  -0.099628;-0.005342;0.214821;,
  -0.082444;-0.005125;0.222132;,
  -0.114435;-0.005342;0.249623;,
  -0.082444;-0.005125;0.222132;,
  -0.122479;0.224407;0.208855;,
  -0.105285;0.224338;0.216170;,
  -0.099628;-0.005342;0.214821;,
  -0.089880;0.335308;0.239519;,
  -0.134580;0.224407;0.237296;,
  -0.117386;0.224338;0.244611;,
  -0.107032;0.335756;0.232222;,
  -0.105285;0.224338;0.216170;,
  -0.107032;0.335756;0.232222;,
  -0.089880;0.335308;0.239519;,
  -0.122479;0.224407;0.208855;,
  0.082179;0.161490;0.068562;,
  0.088063;-0.005342;0.056479;,
  0.105206;-0.004931;0.063461;,
  0.065000;0.161579;0.061565;,
  0.105206;-0.004931;0.063461;,
  0.074600;-0.005342;0.021135;,
  0.091744;-0.004931;0.028118;,
  0.088063;-0.005342;0.056479;,
  0.091744;-0.004931;0.028118;,
  0.053998;0.161579;0.032681;,
  0.071164;0.161324;0.039672;,
  0.074600;-0.005342;0.021135;,
  0.098311;0.231233;0.045723;,
  0.065000;0.161579;0.061565;,
  0.082179;0.161490;0.068562;,
  0.081332;0.232197;0.038807;,
  0.071164;0.161324;0.039672;,
  0.081332;0.232197;0.038807;,
  0.098311;0.231233;0.045723;,
  0.053998;0.161579;0.032681;,
  -0.132871;0.224103;0.128859;,
  -0.112951;-0.005342;0.113173;,
  -0.129036;-0.004795;0.105568;,
  -0.116744;0.224407;0.136483;,
  -0.129036;-0.004795;0.105568;,
  -0.150768;-0.005342;0.112628;,
  -0.166853;-0.004795;0.105023;,
  -0.112951;-0.005342;0.113173;,
  -0.166853;-0.004795;0.105023;,
  -0.147649;0.224407;0.136038;,
  -0.163790;0.224242;0.128406;,
  -0.150768;-0.005342;0.112628;,
  -0.147752;0.334640;0.105387;,
  -0.116744;0.224407;0.136483;,
  -0.132871;0.224103;0.128859;,
  -0.131860;0.335756;0.112900;,
  -0.163790;0.224242;0.128406;,
  -0.131860;0.335756;0.112900;,
  -0.147752;0.334640;0.105387;,
  -0.147649;0.224407;0.136038;,
  0.065468;0.287767;-0.163183;,
  0.073018;-0.005342;-0.177330;,
  0.055987;-0.005078;-0.184802;,
  0.082511;0.287886;-0.155705;,
  0.055987;-0.005078;-0.184802;,
  0.040985;-0.005342;-0.157222;,
  0.023954;-0.005078;-0.164695;,
  0.073018;-0.005342;-0.177330;,
  0.023954;-0.005078;-0.164695;,
  0.056333;0.287886;-0.139273;,
  0.039288;0.287817;-0.146752;,
  0.040985;-0.005342;-0.157222;,
  0.040018;0.398691;-0.174728;,
  0.082511;0.287886;-0.155705;,
  0.065468;0.287767;-0.163183;,
  0.057002;0.399234;-0.167276;,
  0.039288;0.287817;-0.146752;,
  0.057002;0.399234;-0.167276;,
  0.040018;0.398691;-0.174728;,
  0.056333;0.287886;-0.139273;,
  0.096180;0.161506;0.129475;,
  0.090006;-0.005342;0.133409;,
  0.072810;-0.005017;0.126235;,
  0.113398;0.161579;0.136659;,
  0.072810;-0.005017;0.126235;,
  0.090341;-0.005342;0.171229;,
  0.073145;-0.005017;0.164054;,
  0.090006;-0.005342;0.133409;,
  0.073145;-0.005017;0.164054;,
  0.113672;0.161579;0.167566;,
  0.096458;0.161425;0.160383;,
  0.090341;-0.005342;0.171229;,
  0.073081;0.231432;0.145187;,
  0.113398;0.161579;0.136659;,
  0.096180;0.161506;0.129475;,
  0.090174;0.232197;0.152319;,
  0.096458;0.161425;0.160383;,
  0.090174;0.232197;0.152319;,
  0.073081;0.231432;0.145187;,
  0.113672;0.161579;0.167566;,
  -0.031869;0.224028;0.061284;,
  -0.033244;-0.005342;0.083582;,
  -0.046986;-0.004266;0.079334;,
  -0.017949;0.224407;0.065588;,
  -0.046986;-0.004266;0.079334;,
  -0.001153;-0.005342;0.103596;,
  -0.014894;-0.004266;0.099348;,
  -0.033244;-0.005342;0.083582;,
  -0.014894;-0.004266;0.099348;,
  0.008277;0.224407;0.081944;,
  -0.005607;0.223816;0.077652;,
  -0.001153;-0.005342;0.103596;,
  -0.030334;0.333632;0.089528;,
  -0.017949;0.224407;0.065588;,
  -0.031869;0.224028;0.061284;,
  -0.017199;0.335756;0.093590;,
  -0.005607;0.223816;0.077652;,
  -0.017199;0.335756;0.093590;,
  -0.030334;0.333632;0.089528;,
  0.008277;0.224407;0.081944;,
  -0.167812;0.161493;-0.005973;,
  -0.173848;-0.005342;0.005341;,
  -0.191003;-0.004943;-0.001667;,
  -0.150625;0.161579;0.001048;,
  -0.191003;-0.004943;-0.001667;,
  -0.161604;-0.005342;0.041125;,
  -0.178759;-0.004943;0.034117;,
  -0.173848;-0.005342;0.005341;,
  -0.178759;-0.004943;0.034117;,
  -0.140619;0.161579;0.030292;,
  -0.157795;0.161336;0.023275;,
  -0.161604;-0.005342;0.041125;,
  -0.184726;0.231262;0.016288;,
  -0.150625;0.161579;0.001048;,
  -0.167812;0.161493;-0.005973;,
  -0.167726;0.232197;0.023233;,
  -0.157795;0.161336;0.023275;,
  -0.167726;0.232197;0.023233;,
  -0.184726;0.231262;0.016288;,
  -0.140619;0.161579;0.030292;,
  -0.058741;0.118039;-0.018988;,
  -0.051155;-0.005342;-0.033150;,
  -0.068186;-0.005078;-0.040623;,
  -0.041698;0.118158;-0.011509;,
  -0.068186;-0.005078;-0.040623;,
  -0.083222;-0.005342;-0.013096;,
  -0.100252;-0.005078;-0.020569;,
  -0.051155;-0.005342;-0.033150;,
  -0.100252;-0.005078;-0.020569;,
  -0.067904;0.117458;0.004879;,
  -0.084948;0.117389;-0.002600;,
  -0.083222;-0.005342;-0.013096;,
  -0.084171;0.228263;-0.030575;,
  -0.041698;0.118158;-0.011509;,
  -0.058741;0.118039;-0.018988;,
  -0.067188;0.228806;-0.023123;,
  -0.084948;0.117389;-0.002600;,
  -0.067188;0.228806;-0.023123;,
  -0.084171;0.228263;-0.030575;,
  -0.067904;0.117458;0.004879;,
  0.108112;0.270492;-0.078730;,
  0.112934;-0.005342;-0.091466;,
  0.095849;-0.005098;-0.098902;,
  0.125207;0.270594;-0.071288;,
  0.095849;-0.005098;-0.098902;,
  0.083846;-0.005342;-0.067294;,
  0.066761;-0.005098;-0.074731;,
  0.112934;-0.005342;-0.091466;,
  0.066761;-0.005098;-0.074731;,
  0.101436;0.270594;-0.051534;,
  0.084339;0.270530;-0.058976;,
  0.083846;-0.005342;-0.067294;,
  0.081346;0.381440;-0.086799;,
  0.125207;0.270594;-0.071288;,
  0.108112;0.270492;-0.078730;,
  0.098390;0.381942;-0.079380;,
  0.084339;0.270530;-0.058976;,
  0.098390;0.381942;-0.079380;,
  0.081346;0.381440;-0.086799;,
  0.101436;0.270594;-0.051534;,
  0.009045;0.055162;0.161263;,
  0.013863;-0.005342;0.148525;,
  -0.003210;-0.005007;0.141093;,
  0.026136;0.055330;0.168702;,
  -0.003210;-0.005007;0.141093;,
  -0.015225;-0.005342;0.172697;,
  -0.032299;-0.005007;0.165265;,
  0.013863;-0.005342;0.148525;,
  -0.032299;-0.005007;0.165265;,
  0.002364;0.055330;0.188456;,
  -0.014732;0.055256;0.181014;,
  -0.015225;-0.005342;0.172697;,
  -0.017646;0.125160;0.153227;,
  0.026136;0.055330;0.168702;,
  0.009045;0.055162;0.161263;,
  -0.000681;0.125948;0.160611;,
  -0.014732;0.055256;0.181014;,
  -0.000681;0.125948;0.160611;,
  -0.017646;0.125160;0.153227;,
  0.002364;0.055330;0.188456;,
  -0.139755;0.117986;-0.107156;,
  -0.141935;-0.005342;-0.086598;,
  -0.158509;-0.004776;-0.092858;,
  -0.123121;0.118158;-0.100874;,
  -0.158509;-0.004776;-0.092858;,
  -0.114910;-0.005342;-0.060139;,
  -0.131484;-0.004776;-0.066399;,
  -0.141935;-0.005342;-0.086598;,
  -0.131484;-0.004776;-0.066399;,
  -0.101035;0.118158;-0.079251;,
  -0.117655;0.117843;-0.085528;,
  -0.114910;-0.005342;-0.060139;,
  -0.144784;0.228353;-0.079548;,
  -0.123121;0.118158;-0.100874;,
  -0.139755;0.117986;-0.107156;,
  -0.128422;0.229507;-0.073369;,
  -0.117655;0.117843;-0.085528;,
  -0.128422;0.229507;-0.073369;,
  -0.144784;0.228353;-0.079548;,
  -0.101035;0.118158;-0.079251;,
  -0.047790;0.118092;-0.141717;,
  -0.054193;-0.005342;-0.134429;,
  -0.071393;-0.005087;-0.141545;,
  -0.030577;0.118158;-0.134596;,
  -0.071393;-0.005087;-0.141545;,
  -0.048394;-0.005342;-0.097056;,
  -0.065594;-0.005087;-0.104171;,
  -0.054193;-0.005342;-0.134429;,
  -0.065594;-0.005087;-0.104171;,
  -0.025838;0.118158;-0.104053;,
  -0.043050;0.118047;-0.111174;,
  -0.048394;-0.005342;-0.097056;,
  -0.068449;0.228982;-0.122839;,
  -0.030577;0.118158;-0.134596;,
  -0.047790;0.118092;-0.141717;,
  -0.051294;0.229507;-0.115742;,
  -0.043050;0.118047;-0.111174;,
  -0.051294;0.229507;-0.115742;,
  -0.068449;0.228982;-0.122839;,
  -0.025838;0.118158;-0.104053;;
  192;
  3;0,1,2;,
  3;1,0,3;,
  3;4,5,6;,
  3;7,8,9;,
  3;8,7,10;,
  3;11,12,13;,
  3;14,15,16;,
  3;15,14,17;,
  3;18,19,20;,
  3;21,22,23;,
  3;22,21,24;,
  3;25,26,27;,
  3;28,29,30;,
  3;29,28,31;,
  3;32,33,34;,
  3;35,36,37;,
  3;36,35,38;,
  3;39,40,41;,
  3;42,43,44;,
  3;43,42,45;,
  3;46,47,48;,
  3;49,50,51;,
  3;50,49,52;,
  3;53,54,55;,
  3;56,57,58;,
  3;57,56,59;,
  3;60,61,62;,
  3;63,64,65;,
  3;64,63,66;,
  3;67,68,69;,
  3;70,71,72;,
  3;71,70,73;,
  3;74,75,76;,
  3;77,78,79;,
  3;78,77,80;,
  3;81,82,83;,
  3;84,85,86;,
  3;85,84,87;,
  3;88,89,90;,
  3;91,92,93;,
  3;92,91,94;,
  3;95,96,97;,
  3;98,99,100;,
  3;99,98,101;,
  3;102,103,104;,
  3;105,106,107;,
  3;106,105,108;,
  3;109,110,111;,
  3;112,113,114;,
  3;113,112,115;,
  3;116,117,118;,
  3;119,120,121;,
  3;120,119,122;,
  3;123,124,125;,
  3;126,127,128;,
  3;127,126,129;,
  3;130,131,132;,
  3;133,134,135;,
  3;134,133,136;,
  3;137,138,139;,
  3;140,141,142;,
  3;141,140,143;,
  3;144,145,146;,
  3;147,148,149;,
  3;148,147,150;,
  3;151,152,153;,
  3;154,155,156;,
  3;155,154,157;,
  3;158,159,160;,
  3;161,162,163;,
  3;162,161,164;,
  3;165,166,167;,
  3;168,169,170;,
  3;169,168,171;,
  3;172,173,174;,
  3;173,172,175;,
  3;176,177,178;,
  3;177,176,179;,
  3;180,181,182;,
  3;181,180,183;,
  3;184,185,186;,
  3;185,184,187;,
  3;188,189,190;,
  3;189,188,191;,
  3;192,193,194;,
  3;193,192,195;,
  3;196,197,198;,
  3;197,196,199;,
  3;200,201,202;,
  3;201,200,203;,
  3;204,205,206;,
  3;205,204,207;,
  3;208,209,210;,
  3;209,208,211;,
  3;212,213,214;,
  3;213,212,215;,
  3;216,217,218;,
  3;217,216,219;,
  3;220,221,222;,
  3;221,220,223;,
  3;224,225,226;,
  3;225,224,227;,
  3;228,229,230;,
  3;229,228,231;,
  3;232,233,234;,
  3;233,232,235;,
  3;236,237,238;,
  3;237,236,239;,
  3;240,241,242;,
  3;241,240,243;,
  3;244,245,246;,
  3;245,244,247;,
  3;248,249,250;,
  3;249,248,251;,
  3;252,253,254;,
  3;253,252,255;,
  3;256,257,258;,
  3;257,256,259;,
  3;260,261,262;,
  3;261,260,263;,
  3;264,265,266;,
  3;265,264,267;,
  3;268,269,270;,
  3;269,268,271;,
  3;272,273,274;,
  3;273,272,275;,
  3;276,277,278;,
  3;277,276,279;,
  3;280,281,282;,
  3;281,280,283;,
  3;284,285,286;,
  3;285,284,287;,
  3;288,289,290;,
  3;289,288,291;,
  3;292,293,294;,
  3;293,292,295;,
  3;296,297,298;,
  3;297,296,299;,
  3;300,301,302;,
  3;301,300,303;,
  3;304,305,306;,
  3;305,304,307;,
  3;308,309,310;,
  3;309,308,311;,
  3;312,313,314;,
  3;313,312,315;,
  3;316,317,318;,
  3;317,316,319;,
  3;320,321,322;,
  3;321,320,323;,
  3;324,325,326;,
  3;325,324,327;,
  3;328,329,330;,
  3;329,328,331;,
  3;332,333,334;,
  3;333,332,335;,
  3;336,337,338;,
  3;337,336,339;,
  3;340,341,342;,
  3;341,340,343;,
  3;344,345,346;,
  3;345,344,347;,
  3;348,349,350;,
  3;349,348,351;,
  3;352,353,354;,
  3;353,352,355;,
  3;356,357,358;,
  3;357,356,359;,
  3;360,361,362;,
  3;361,360,363;,
  3;364,365,366;,
  3;365,364,367;,
  3;368,369,370;,
  3;369,368,371;,
  3;372,373,374;,
  3;373,372,375;,
  3;376,377,378;,
  3;377,376,379;,
  3;380,381,382;,
  3;381,380,383;,
  3;384,385,386;,
  3;385,384,387;,
  3;388,389,390;,
  3;389,388,391;,
  3;392,393,394;,
  3;393,392,395;,
  3;396,397,398;,
  3;397,396,399;,
  3;400,401,402;,
  3;401,400,403;,
  3;404,405,406;,
  3;405,404,407;;

  MeshNormals {
   408;
   -0.915458;-0.101195;-0.389482;,
   -0.915458;-0.101195;-0.389482;,
   -0.915458;-0.101195;-0.389482;,
   -0.915458;-0.101195;-0.389482;,
   -0.900568;0.205293;-0.383186;,
   -0.900568;0.205293;-0.383186;,
   -0.900568;0.205293;-0.383186;,
   -0.925492;-0.138599;0.352497;,
   -0.925492;-0.138599;0.352497;,
   -0.925492;-0.138599;0.352497;,
   -0.925492;-0.138599;0.352497;,
   -0.887218;0.314106;0.337907;,
   -0.887218;0.314106;0.337907;,
   -0.887218;0.314106;0.337907;,
   -0.014299;-0.101196;0.994764;,
   -0.014299;-0.101196;0.994764;,
   -0.014299;-0.101196;0.994764;,
   -0.014299;-0.101196;0.994764;,
   -0.014100;0.205299;0.978598;,
   -0.014100;0.205299;0.978598;,
   -0.014100;0.205299;0.978598;,
   0.529988;-0.079398;0.844280;,
   0.529988;-0.079398;0.844280;,
   0.529988;-0.079398;0.844280;,
   0.529988;-0.079398;0.844280;,
   0.520317;0.205307;0.828927;,
   0.520317;0.205307;0.828927;,
   0.520317;0.205307;0.828927;,
   0.990309;-0.138601;-0.008800;,
   0.990309;-0.138601;-0.008800;,
   0.990309;-0.138601;-0.008800;,
   0.990309;-0.138601;-0.008800;,
   0.949357;0.314086;-0.008400;,
   0.949357;0.314086;-0.008400;,
   0.949357;0.314086;-0.008400;,
   0.526469;-0.101194;-0.844150;,
   0.526469;-0.101194;-0.844150;,
   0.526469;-0.101194;-0.844150;,
   0.526469;-0.101194;-0.844150;,
   0.517917;0.205307;-0.830428;,
   0.517917;0.205307;-0.830428;,
   0.517917;0.205307;-0.830428;,
   0.937017;-0.138603;-0.320606;,
   0.937017;-0.138603;-0.320606;,
   0.937017;-0.138603;-0.320606;,
   0.937017;-0.138603;-0.320606;,
   0.898284;0.314095;-0.307295;,
   0.898284;0.314095;-0.307295;,
   0.898284;0.314095;-0.307295;,
   0.522579;-0.186393;0.831967;,
   0.522579;-0.186393;0.831967;,
   0.522579;-0.186393;0.831967;,
   0.522579;-0.186393;0.831967;,
   0.514913;0.206005;0.832121;,
   0.514913;0.206005;0.832121;,
   0.514913;0.206005;0.832121;,
   0.636798;-0.084400;0.766397;,
   0.636798;-0.084400;0.766397;,
   0.636798;-0.084400;0.766397;,
   0.636798;-0.084400;0.766397;,
   0.625514;0.205305;0.752717;,
   0.625514;0.205305;0.752717;,
   0.625514;0.205305;0.752717;,
   0.596435;-0.359321;0.717742;,
   0.596435;-0.359321;0.717742;,
   0.596435;-0.359321;0.717742;,
   0.596435;-0.359321;0.717742;,
   0.606783;0.314091;0.730179;,
   0.606783;0.314091;0.730179;,
   0.606783;0.314091;0.730179;,
   0.687392;-0.185898;-0.702092;,
   0.687392;-0.185898;-0.702092;,
   0.687392;-0.185898;-0.702092;,
   0.687392;-0.185898;-0.702092;,
   0.684706;0.205302;-0.699306;,
   0.684706;0.205302;-0.699306;,
   0.684706;0.205302;-0.699306;,
   0.970946;-0.185890;-0.150692;,
   0.970946;-0.185890;-0.150692;,
   0.970946;-0.185890;-0.150692;,
   0.970946;-0.185890;-0.150692;,
   0.967119;0.205304;-0.150103;,
   0.967119;0.205304;-0.150103;,
   0.967119;0.205304;-0.150103;,
   0.915442;0.101205;0.389518;,
   0.915442;0.101205;0.389518;,
   0.915442;0.101205;0.389518;,
   0.915442;0.101205;0.389518;,
   0.900528;-0.205606;0.383112;,
   0.900528;-0.205606;0.383112;,
   0.900528;-0.205606;0.383112;,
   0.925282;0.138997;-0.352893;,
   0.925282;0.138997;-0.352893;,
   0.925282;0.138997;-0.352893;,
   0.925282;0.138997;-0.352893;,
   0.887295;-0.315398;-0.336498;,
   0.887295;-0.315398;-0.336498;,
   0.887295;-0.315398;-0.336498;,
   0.014601;0.101404;-0.994738;,
   0.014601;0.101404;-0.994738;,
   0.014601;0.101404;-0.994738;,
   0.014601;0.101404;-0.994738;,
   0.013399;-0.205992;-0.978462;,
   0.013399;-0.205992;-0.978462;,
   0.013399;-0.205992;-0.978462;,
   -0.529911;0.079502;-0.844318;,
   -0.529911;0.079502;-0.844318;,
   -0.529911;0.079502;-0.844318;,
   -0.529911;0.079502;-0.844318;,
   -0.520506;-0.205702;-0.828710;,
   -0.520506;-0.205702;-0.828710;,
   -0.520506;-0.205702;-0.828710;,
   -0.990266;0.138895;0.009000;,
   -0.990266;0.138895;0.009000;,
   -0.990266;0.138895;0.009000;,
   -0.990266;0.138895;0.009000;,
   -0.948995;-0.315198;0.007700;,
   -0.948995;-0.315198;0.007700;,
   -0.948995;-0.315198;0.007700;,
   -0.526064;0.101693;0.844343;,
   -0.526064;0.101693;0.844343;,
   -0.526064;0.101693;0.844343;,
   -0.526064;0.101693;0.844343;,
   -0.518719;-0.206507;0.829630;,
   -0.518719;-0.206507;0.829630;,
   -0.518719;-0.206507;0.829630;,
   -0.936834;0.138905;0.321011;,
   -0.936834;0.138905;0.321011;,
   -0.936834;0.138905;0.321011;,
   -0.936834;0.138905;0.321011;,
   -0.898275;-0.315391;0.305991;,
   -0.898275;-0.315391;0.305991;,
   -0.898275;-0.315391;0.305991;,
   -0.522395;0.186798;-0.831992;,
   -0.522395;0.186798;-0.831992;,
   -0.522395;0.186798;-0.831992;,
   -0.522395;0.186798;-0.831992;,
   -0.515114;-0.206306;-0.831923;,
   -0.515114;-0.206306;-0.831923;,
   -0.515114;-0.206306;-0.831923;,
   -0.636798;0.084400;-0.766397;,
   -0.636798;0.084400;-0.766397;,
   -0.636798;0.084400;-0.766397;,
   -0.636798;0.084400;-0.766397;,
   -0.625618;-0.205706;-0.752521;,
   -0.625618;-0.205706;-0.752521;,
   -0.625618;-0.205706;-0.752521;,
   -0.595489;0.361393;-0.717487;,
   -0.595489;0.361393;-0.717487;,
   -0.595489;0.361393;-0.717487;,
   -0.595489;0.361393;-0.717487;,
   -0.607116;-0.315209;-0.729420;,
   -0.607116;-0.315209;-0.729420;,
   -0.607116;-0.315209;-0.729420;,
   -0.686904;0.186901;0.702304;,
   -0.686904;0.186901;0.702304;,
   -0.686904;0.186901;0.702304;,
   -0.686904;0.186901;0.702304;,
   -0.685107;-0.206002;0.698707;,
   -0.685107;-0.206002;0.698707;,
   -0.685107;-0.206002;0.698707;,
   -0.970854;0.186291;0.150793;,
   -0.970854;0.186291;0.150793;,
   -0.970854;0.186291;0.150793;,
   -0.970854;0.186291;0.150793;,
   -0.967083;-0.205696;0.149797;,
   -0.967083;-0.205696;0.149797;,
   -0.967083;-0.205696;0.149797;,
   -0.391520;0.015001;0.920047;,
   -0.391520;0.015001;0.920047;,
   -0.391520;0.015001;0.920047;,
   -0.391520;0.015001;0.920047;,
   0.010700;-0.999932;0.004600;,
   0.010700;-0.999932;0.004600;,
   0.010700;-0.999932;0.004600;,
   0.010700;-0.999932;0.004600;,
   0.391399;0.015000;-0.920099;,
   0.391399;0.015000;-0.920099;,
   0.391399;0.015000;-0.920099;,
   0.391399;0.015000;-0.920099;,
   -0.386094;0.137298;0.912185;,
   -0.386094;0.137298;0.912185;,
   -0.386094;0.137298;0.912185;,
   -0.386094;0.137298;0.912185;,
   0.389597;0.137299;-0.910694;,
   0.389597;0.137299;-0.910694;,
   0.389597;0.137299;-0.910694;,
   0.389597;0.137299;-0.910694;,
   -0.375398;-0.080100;0.923396;,
   -0.375398;-0.080100;0.923396;,
   -0.375398;-0.080100;0.923396;,
   -0.375398;-0.080100;0.923396;,
   0.028401;-0.999538;-0.010800;,
   0.028401;-0.999538;-0.010800;,
   0.028401;-0.999538;-0.010800;,
   0.028401;-0.999538;-0.010800;,
   0.374489;0.110097;-0.920672;,
   0.374489;0.110097;-0.920672;,
   0.374489;0.110097;-0.920672;,
   0.374489;0.110097;-0.920672;,
   -0.342204;0.361004;0.867509;,
   -0.342204;0.361004;0.867509;,
   -0.342204;0.361004;0.867509;,
   -0.342204;0.361004;0.867509;,
   0.374395;-0.064999;-0.924988;,
   0.374395;-0.064999;-0.924988;,
   0.374395;-0.064999;-0.924988;,
   0.374395;-0.064999;-0.924988;,
   0.425979;0.098495;-0.899356;,
   0.425979;0.098495;-0.899356;,
   0.425979;0.098495;-0.899356;,
   0.425979;0.098495;-0.899356;,
   0.001100;-0.997258;-0.073997;,
   0.001100;-0.997258;-0.073997;,
   0.001100;-0.997258;-0.073997;,
   0.001100;-0.997258;-0.073997;,
   -0.426694;-0.086099;0.900288;,
   -0.426694;-0.086099;0.900288;,
   -0.426694;-0.086099;0.900288;,
   -0.426694;-0.086099;0.900288;,
   0.428503;-0.131601;-0.893905;,
   0.428503;-0.131601;-0.893905;,
   0.428503;-0.131601;-0.893905;,
   0.428503;-0.131601;-0.893905;,
   -0.422600;0.242400;0.873299;,
   -0.422600;0.242400;0.873299;,
   -0.422600;0.242400;0.873299;,
   -0.422600;0.242400;0.873299;,
   0.401393;0.054499;-0.914283;,
   0.401393;0.054499;-0.914283;,
   0.401393;0.054499;-0.914283;,
   0.401393;0.054499;-0.914283;,
   -0.009100;-0.999853;-0.014499;,
   -0.009100;-0.999853;-0.014499;,
   -0.009100;-0.999853;-0.014499;,
   -0.009100;-0.999853;-0.014499;,
   -0.401701;-0.035000;0.915102;,
   -0.401701;-0.035000;0.915102;,
   -0.401701;-0.035000;0.915102;,
   -0.401701;-0.035000;0.915102;,
   0.401808;-0.003100;-0.915719;,
   0.401808;-0.003100;-0.915719;,
   0.401808;-0.003100;-0.915719;,
   0.401808;-0.003100;-0.915719;,
   -0.394692;0.226796;0.890383;,
   -0.394692;0.226796;0.890383;,
   -0.394692;0.226796;0.890383;,
   -0.394692;0.226796;0.890383;,
   0.384593;-0.035999;-0.922384;,
   0.384593;-0.035999;-0.922384;,
   0.384593;-0.035999;-0.922384;,
   0.384593;-0.035999;-0.922384;,
   -0.019000;-0.999819;0.000200;,
   -0.019000;-0.999819;0.000200;,
   -0.019000;-0.999819;0.000200;,
   -0.019000;-0.999819;0.000200;,
   -0.383699;0.073900;0.920497;,
   -0.383699;0.073900;0.920497;,
   -0.383699;0.073900;0.920497;,
   -0.383699;0.073900;0.920497;,
   0.358986;0.314487;-0.878765;,
   0.358986;0.314487;-0.878765;,
   0.358986;0.314487;-0.878765;,
   0.358986;0.314487;-0.878765;,
   -0.385707;0.070601;0.919916;,
   -0.385707;0.070601;0.919916;,
   -0.385707;0.070601;0.919916;,
   -0.385707;0.070601;0.919916;,
   0.291897;-0.094299;-0.951790;,
   0.291897;-0.094299;-0.951790;,
   0.291897;-0.094299;-0.951790;,
   0.291897;-0.094299;-0.951790;,
   -0.149097;-0.959481;0.239095;,
   -0.149097;-0.959481;0.239095;,
   -0.149097;-0.959481;0.239095;,
   -0.149097;-0.959481;0.239095;,
   -0.292201;0.102000;0.950902;,
   -0.292201;0.102000;0.950902;,
   -0.292201;0.102000;0.950902;,
   -0.292201;0.102000;0.950902;,
   0.267206;0.235105;-0.934520;,
   0.267206;0.235105;-0.934520;,
   0.267206;0.235105;-0.934520;,
   0.267206;0.235105;-0.934520;,
   -0.276409;-0.163505;0.947029;,
   -0.276409;-0.163505;0.947029;,
   -0.276409;-0.163505;0.947029;,
   -0.276409;-0.163505;0.947029;,
   0.376492;-0.076198;-0.923281;,
   0.376492;-0.076198;-0.923281;,
   0.376492;-0.076198;-0.923281;,
   0.376492;-0.076198;-0.923281;,
   -0.027000;-0.999592;0.009300;,
   -0.027000;-0.999592;0.009300;,
   -0.027000;-0.999592;0.009300;,
   -0.027000;-0.999592;0.009300;,
   -0.375587;0.107196;0.920567;,
   -0.375587;0.107196;0.920567;,
   -0.375587;0.107196;0.920567;,
   -0.375587;0.107196;0.920567;,
   0.343913;0.358113;-0.868032;,
   0.343913;0.358113;-0.868032;,
   0.343913;0.358113;-0.868032;,
   0.343913;0.358113;-0.868032;,
   -0.376103;-0.052200;0.925106;,
   -0.376103;-0.052200;0.925106;,
   -0.376103;-0.052200;0.925106;,
   -0.376103;-0.052200;0.925106;,
   0.398907;0.128702;-0.907915;,
   0.398907;0.128702;-0.907915;,
   0.398907;0.128702;-0.907915;,
   0.398907;0.128702;-0.907915;,
   -0.009100;-0.999852;-0.014599;,
   -0.009100;-0.999852;-0.014599;,
   -0.009100;-0.999852;-0.014599;,
   -0.009100;-0.999852;-0.014599;,
   -0.400813;-0.083703;0.912328;,
   -0.400813;-0.083703;0.912328;,
   -0.400813;-0.083703;0.912328;,
   -0.400813;-0.083703;0.912328;,
   0.401891;-0.003500;-0.915681;,
   0.401891;-0.003500;-0.915681;,
   0.401891;-0.003500;-0.915681;,
   0.401891;-0.003500;-0.915681;,
   -0.394803;0.226902;0.890307;,
   -0.394803;0.226902;0.890307;,
   -0.394803;0.226902;0.890307;,
   -0.394803;0.226902;0.890307;,
   0.398804;0.049301;-0.915710;,
   0.398804;0.049301;-0.915710;,
   0.398804;0.049301;-0.915710;,
   0.398804;0.049301;-0.915710;,
   -0.009400;-0.999892;-0.011300;,
   -0.009400;-0.999892;-0.011300;,
   -0.009400;-0.999892;-0.011300;,
   -0.009400;-0.999892;-0.011300;,
   -0.399105;-0.026900;0.916511;,
   -0.399105;-0.026900;0.916511;,
   -0.399105;-0.026900;0.916511;,
   -0.399105;-0.026900;0.916511;,
   0.398499;0.029400;-0.916698;,
   0.398499;0.029400;-0.916698;,
   0.398499;0.029400;-0.916698;,
   0.398499;0.029400;-0.916698;,
   -0.392892;0.213396;0.894482;,
   -0.392892;0.213396;0.894482;,
   -0.392892;0.213396;0.894482;,
   -0.392892;0.213396;0.894482;,
   0.390296;0.219298;-0.894191;,
   0.390296;0.219298;-0.894191;,
   0.390296;0.219298;-0.894191;,
   0.390296;0.219298;-0.894191;,
   -0.012900;-0.999797;-0.015500;,
   -0.012900;-0.999797;-0.015500;,
   -0.012900;-0.999797;-0.015500;,
   -0.012900;-0.999797;-0.015500;,
   -0.396926;-0.121608;0.909759;,
   -0.396926;-0.121608;0.909759;,
   -0.396926;-0.121608;0.909759;,
   -0.396926;-0.121608;0.909759;,
   0.397598;0.046200;-0.916396;,
   0.397598;0.046200;-0.916396;,
   0.397598;0.046200;-0.916396;,
   0.397598;0.046200;-0.916396;,
   -0.384283;0.325685;0.863861;,
   -0.384283;0.325685;0.863861;,
   -0.384283;0.325685;0.863861;,
   -0.384283;0.325685;0.863861;,
   0.347082;-0.160192;-0.924052;,
   0.347082;-0.160192;-0.924052;,
   0.347082;-0.160192;-0.924052;,
   0.347082;-0.160192;-0.924052;,
   -0.055398;-0.996859;0.056598;,
   -0.055398;-0.996859;0.056598;,
   -0.055398;-0.996859;0.056598;,
   -0.055398;-0.996859;0.056598;,
   -0.346212;0.182006;0.920332;,
   -0.346212;0.182006;0.920332;,
   -0.346212;0.182006;0.920332;,
   -0.346212;0.182006;0.920332;,
   0.334290;0.241993;-0.910873;,
   0.334290;0.241993;-0.910873;,
   0.334290;0.241993;-0.910873;,
   0.334290;0.241993;-0.910873;,
   -0.344890;-0.134396;0.928972;,
   -0.344890;-0.134396;0.928972;,
   -0.344890;-0.134396;0.928972;,
   -0.344890;-0.134396;0.928972;,
   0.380912;-0.074202;-0.921629;,
   0.380912;-0.074202;-0.921629;,
   0.380912;-0.074202;-0.921629;,
   0.380912;-0.074202;-0.921629;,
   -0.015800;-0.999872;0.002500;,
   -0.015800;-0.999872;0.002500;,
   -0.015800;-0.999872;0.002500;,
   -0.015800;-0.999872;0.002500;,
   -0.379000;0.121400;0.917399;,
   -0.379000;0.121400;0.917399;,
   -0.379000;0.121400;0.917399;,
   -0.379000;0.121400;0.917399;,
   0.369507;0.222004;-0.902318;,
   0.369507;0.222004;-0.902318;,
   0.369507;0.222004;-0.902318;,
   0.369507;0.222004;-0.902318;,
   -0.382417;0.009600;0.923940;,
   -0.382417;0.009600;0.923940;,
   -0.382417;0.009600;0.923940;,
   -0.382417;0.009600;0.923940;;
   192;
   3;0,1,2;,
   3;1,0,3;,
   3;4,5,6;,
   3;7,8,9;,
   3;8,7,10;,
   3;11,12,13;,
   3;14,15,16;,
   3;15,14,17;,
   3;18,19,20;,
   3;21,22,23;,
   3;22,21,24;,
   3;25,26,27;,
   3;28,29,30;,
   3;29,28,31;,
   3;32,33,34;,
   3;35,36,37;,
   3;36,35,38;,
   3;39,40,41;,
   3;42,43,44;,
   3;43,42,45;,
   3;46,47,48;,
   3;49,50,51;,
   3;50,49,52;,
   3;53,54,55;,
   3;56,57,58;,
   3;57,56,59;,
   3;60,61,62;,
   3;63,64,65;,
   3;64,63,66;,
   3;67,68,69;,
   3;70,71,72;,
   3;71,70,73;,
   3;74,75,76;,
   3;77,78,79;,
   3;78,77,80;,
   3;81,82,83;,
   3;84,85,86;,
   3;85,84,87;,
   3;88,89,90;,
   3;91,92,93;,
   3;92,91,94;,
   3;95,96,97;,
   3;98,99,100;,
   3;99,98,101;,
   3;102,103,104;,
   3;105,106,107;,
   3;106,105,108;,
   3;109,110,111;,
   3;112,113,114;,
   3;113,112,115;,
   3;116,117,118;,
   3;119,120,121;,
   3;120,119,122;,
   3;123,124,125;,
   3;126,127,128;,
   3;127,126,129;,
   3;130,131,132;,
   3;133,134,135;,
   3;134,133,136;,
   3;137,138,139;,
   3;140,141,142;,
   3;141,140,143;,
   3;144,145,146;,
   3;147,148,149;,
   3;148,147,150;,
   3;151,152,153;,
   3;154,155,156;,
   3;155,154,157;,
   3;158,159,160;,
   3;161,162,163;,
   3;162,161,164;,
   3;165,166,167;,
   3;168,169,170;,
   3;169,168,171;,
   3;172,173,174;,
   3;173,172,175;,
   3;176,177,178;,
   3;177,176,179;,
   3;180,181,182;,
   3;181,180,183;,
   3;184,185,186;,
   3;185,184,187;,
   3;188,189,190;,
   3;189,188,191;,
   3;192,193,194;,
   3;193,192,195;,
   3;196,197,198;,
   3;197,196,199;,
   3;200,201,202;,
   3;201,200,203;,
   3;204,205,206;,
   3;205,204,207;,
   3;208,209,210;,
   3;209,208,211;,
   3;212,213,214;,
   3;213,212,215;,
   3;216,217,218;,
   3;217,216,219;,
   3;220,221,222;,
   3;221,220,223;,
   3;224,225,226;,
   3;225,224,227;,
   3;228,229,230;,
   3;229,228,231;,
   3;232,233,234;,
   3;233,232,235;,
   3;236,237,238;,
   3;237,236,239;,
   3;240,241,242;,
   3;241,240,243;,
   3;244,245,246;,
   3;245,244,247;,
   3;248,249,250;,
   3;249,248,251;,
   3;252,253,254;,
   3;253,252,255;,
   3;256,257,258;,
   3;257,256,259;,
   3;260,261,262;,
   3;261,260,263;,
   3;264,265,266;,
   3;265,264,267;,
   3;268,269,270;,
   3;269,268,271;,
   3;272,273,274;,
   3;273,272,275;,
   3;276,277,278;,
   3;277,276,279;,
   3;280,281,282;,
   3;281,280,283;,
   3;284,285,286;,
   3;285,284,287;,
   3;288,289,290;,
   3;289,288,291;,
   3;292,293,294;,
   3;293,292,295;,
   3;296,297,298;,
   3;297,296,299;,
   3;300,301,302;,
   3;301,300,303;,
   3;304,305,306;,
   3;305,304,307;,
   3;308,309,310;,
   3;309,308,311;,
   3;312,313,314;,
   3;313,312,315;,
   3;316,317,318;,
   3;317,316,319;,
   3;320,321,322;,
   3;321,320,323;,
   3;324,325,326;,
   3;325,324,327;,
   3;328,329,330;,
   3;329,328,331;,
   3;332,333,334;,
   3;333,332,335;,
   3;336,337,338;,
   3;337,336,339;,
   3;340,341,342;,
   3;341,340,343;,
   3;344,345,346;,
   3;345,344,347;,
   3;348,349,350;,
   3;349,348,351;,
   3;352,353,354;,
   3;353,352,355;,
   3;356,357,358;,
   3;357,356,359;,
   3;360,361,362;,
   3;361,360,363;,
   3;364,365,366;,
   3;365,364,367;,
   3;368,369,370;,
   3;369,368,371;,
   3;372,373,374;,
   3;373,372,375;,
   3;376,377,378;,
   3;377,376,379;,
   3;380,381,382;,
   3;381,380,383;,
   3;384,385,386;,
   3;385,384,387;,
   3;388,389,390;,
   3;389,388,391;,
   3;392,393,394;,
   3;393,392,395;,
   3;396,397,398;,
   3;397,396,399;,
   3;400,401,402;,
   3;401,400,403;,
   3;404,405,406;,
   3;405,404,407;;
  }

  MeshMaterialList {
   1;
   192;
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0;

   Material  {
    0.525490;0.023529;0.023529;1.000000;;
    0.000000;
    0.000000;0.000000;0.000000;;
    0.000000;0.000000;0.000000;;
   }
  }
 }
}

AnimTicksPerSecond  {
 4800;
}

AnimationSet Anim1 {
 

 Animation {
  
  { Grass_Short }

  AnimationKey S {
   1;
   2;
   0;3;1.000000,1.000000,1.000000;;,
   16000;3;1.000000,1.000000,1.000000;;;
  }

  AnimationKey R {
   0;
   2;
   0;4;1.000000,0.000000,0.000000,0.000000;;,
   16000;4;1.000000,0.000000,0.000000,0.000000;;;
  }

  AnimationKey T {
   2;
   2;
   0;3;0.000000,0.000000,0.000000;;,
   16000;3;0.000000,0.000000,0.000000;;;
  }
 }
}