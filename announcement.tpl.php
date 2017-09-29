<h3>Announcement</h3>
<?php print $form; ?>
<hr>
<table class="sticky-enabled table-select-processed tableheader-processed sticky-table">
    <thead>
      <tr>
        <th># </th>
        <th>Announcement</th>
        <th>Action</th>
      </tr>
    </thead>
    <tbody>
      <?php $imageUrl = base_path().'upload/announcement/' ;?>
      <?php foreach ($result as $key => $value) { ?>
          <tr>
            <td><img src="<?php echo $imageUrl ?><?php echo(!empty($value->thumbnail)) ? $value->thumbnail : 'building_s.jpg' ?>"> </td>
            <td><a href="<?php echo $value->url; ?>"><?php echo $value->title; ?></a></td>
            <td><a class="btn btn-primary" href="announcement/?id=<?php echo $value->id; ?>" role="button">Edit</a></td>
          </tr>
      <?php } ?>
      
    </tbody>
</table>