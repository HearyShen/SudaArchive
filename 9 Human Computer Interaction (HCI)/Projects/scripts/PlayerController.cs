using System.Collections;
using System.Collections.Generic;
using UnityEngine.UI;
using UnityEngine;

public class PlayerController : MonoBehaviour {

    public float speed;
    public AudioSource die_audio;
    public Text sectionText;
    public Text sweetCountText;
    public Text centerText;
    public Text notationText;

    private Rigidbody rb;
    private int sweetCount;
    private int lifeCount;
    private int section;

    void Start()
    {
        rb = GetComponent<Rigidbody>();
        sweetCount = 0;
        lifeCount = 1;
        section = 1;
        setCountText();
        setSectionText();
        centerText.text = "神 奇 滚 蛋";
        notationText.text = "14计科 - 沈家赟";
    }

    void FixedUpdate()
    {
        float moveHorizontal = Input.GetAxis("Horizontal");
        float moveVertical = Input.GetAxis("Vertical");
        float moveJump = 0;

        if (section >= 2)
        {
            if (Input.GetKeyDown("space"))
                moveJump = 24 + section*8;
            else
                moveJump = 0;
        }

        Vector3 movement = new Vector3(moveHorizontal, moveJump, moveVertical);

        rb.AddForce(movement * speed);
    }

    void OnTriggerEnter(Collider other)
    {
        if (other.gameObject.CompareTag("Sweet"))
        {
            GetComponent<AudioSource>().Play();
            transform.localScale += new Vector3(0.1F*2, 0.145F*2, 0.1F*2);
            other.gameObject.SetActive(false);
            sweetCount++;
            setCountText();
        }
        if (other.gameObject.CompareTag("Toxic"))
        {
            die_audio.Play();
            //GetComponent<AudioSource>().Play();
            //transform.localScale += new Vector3(-0.1F, -0.145F, -0.1F);
            transform.localScale = new Vector3(0.1F, 0.145F, 0.1F);
            other.gameObject.SetActive(false);
            if (--lifeCount <= 0)
            {
                setCenterText();
            }
            setCountText();
        }
        if (other.gameObject.CompareTag("newSection"))
        {
            speed += section;
            other.gameObject.SetActive(false);
            clearCenterText();
            setNotationText();
        }
        if (other.gameObject.CompareTag("clearCenterText"))
        {
            other.gameObject.SetActive(false);
            clearCenterText();
        }
        if (other.gameObject.CompareTag("finishSection"))
        {
            other.gameObject.SetActive(false);
            setCenterText();
            section++;
            setSectionText();
        }
    }

    void setSectionText()
    {
        sectionText.text = "关卡: " + section.ToString();
    }

    void setCountText()
    {
        sweetCountText.text = "方块: " + sweetCount.ToString() + "\n生命: " + lifeCount.ToString();
    }

    void setCenterText()
    {
        if (lifeCount > 0)
            centerText.text = "关卡 - " + section + " 成功！";
        else
            centerText.text = "失 败 ：你 死 了 ！";
    }

    void setNotationText()
    {
        string notes = "";

        if(section == 1)
        {
            notes = "使用 [方向键/WASD] 滚蛋\n吞方块长大，以翻阅障碍。";
        }
        if (section == 2)
        {
            notes = "跳跃技能解锁，按<空格>！\n按 [+/-] 可以缩放视角";
        }
        if (section == 3)
        {
            notes = "穿越树林，小心毒药丸！\n跳跃、运动能力提升！";
        }
        notationText.text = "关卡 - " + section + "：\n" + notes;
    }

    void clearCenterText()
    {
        centerText.text = "";
        notationText.text = "";
    }
}
