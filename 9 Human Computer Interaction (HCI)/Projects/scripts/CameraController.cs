using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraController : MonoBehaviour {

    public GameObject player;

    private Vector3 offset;

    void Start()
    {
        offset = transform.position - player.transform.position;
    }

    void LateUpdate()
    {
        if (Input.GetKey("=")|| Input.GetKey("+"))
        {
            //offset = offset + new Vector3(0, 0.1F, 0.1F);
            offset = new Vector3(offset.x*0.99F, offset.y*0.99F, offset.z*0.99F);
        }
        if (Input.GetKey("-")|| Input.GetKey("_"))
        {
            //offset = offset - new Vector3(0, 0.1F, 0.1F);
            offset = new Vector3(offset.x * 1.01F, offset.y * 1.01F, offset.z * 1.01F);
        }
        transform.position = player.transform.position + offset;
    }
}
