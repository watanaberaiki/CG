float4 main( float4 pos : POSITION ) : SV_POSITION
{
	return pos* float4(1.5,1.5, 1,1);
}