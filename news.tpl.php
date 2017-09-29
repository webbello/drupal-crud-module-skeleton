<div class="cContainer">
    <div class="row clearfix">
        <div class="col-xs-12 col-sm-12 col-md-6 col-lg-6 col-xl-6">
            <h4 class="text-center"><span>Announcement</span></h4>
            <div class="newsDiv newsDivScroll padRight15">
                <?php $imageUrl = base_path().'upload/announcement/' ;?>
                <?php foreach ($result['announcements'] as $key => $value) { ?>
                <div class="newsContent clearfix">
                    <a href="<?php echo $value->url; ?>">
                        <span class="imageDiv">
                            <img src="<?php echo $imageUrl ?><?php echo(!empty($value->thumbnail)) ? $value->thumbnail : 'building_s.jpg' ?>" class="img-fluid mCS_img_loaded" alt="img">
                        </span>
                        <span class="content">
                            <p><a href="<?php echo $value->url; ?>"><?php echo $value->title; ?></a></p>
                        </span>  
                    </a>
                </div>
                <?php } ?>
            </div>
        </div>
        <div class="col-xs-12 col-sm-12 col-md-6  col-lg-6  col-xl-6 ">
            <h4 class="text-center"><span>ONGOING/UPCOMING COURSES</span></h4>
            <div class="newsDiv newsDivScroll padLeft15">
                <?php $imageUrl = base_path().'upload/courses/' ;?>
                <?php foreach ($result['courses'] as $key => $value) { ?>
                <div class="newsContent clearfix">
                    <a href="<?php echo $value->url; ?>">
                        <span class="imageDiv">
                            <img src="<?php echo $imageUrl ?><?php echo(!empty($value->thumbnail)) ? $value->thumbnail : 'building_s.jpg' ?>" class="img-fluid mCS_img_loaded" alt="img">
                        </span>
                        <span class="content">
                            <p><a href="<?php echo $value->url; ?>"><?php echo $value->title; ?></a></p>
                        </span>  
                    </a>
                </div>
                <?php } ?>
            </div>
        </div>
    </div>
</div>
